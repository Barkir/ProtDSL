require_relative "base"
require_relative "var"

module SimInfra
    class Scope

        include GlobalCounter # used for temp variables IDs
        attr_reader :tree, :vars, :parent
        def initialize(parent); @tree = []; @vars = {}; end
        # resolve allows to convert Ruby Integer constants to Constant instance

        def var(name, type)
            @vars[name] = SimInfra::Var.new(self, name, type) # return var
            instance_eval "def #{name.to_s}(); return @vars[:#{name.to_s}]; end"
            stmt :new_var, [@vars[name]] # returns @vars[name]
        end

        def add_var(name, type); var(name, type); self; end

        def resolve_const(what)
            return what if (what.class== Var) or (what.class== Constant) # or other known classes
            return Constant.new(self, "const_#{next_counter}", what) if (what.class== Integer)
        end

        def binOp(a,b, op);
            a = resolve_const(a); b = resolve_const(b)
            # TODO: check constant size <= bitsize(var)
            # assert(a.type== b.type|| a.type == :iconst || b.type== :iconst)

            stmt op, [tmpvar(a.type), a, b]
        end

        ALL_TYPES.each do |type|
            type.each do |op|
                define_method(op) do |a, b|
                    binOp(a, b, op)
                end
            end
        end


        private def tmpvar(type); var("_tmp#{next_counter}".to_sym, type); end
        # stmtadds statement into tree and returns operand[0]
        # which result in near all cases
        def stmt(name, operands, attrs= nil);
            @tree << IrStmt.new(name, operands, attrs); operands[0]
        end
    end
end
