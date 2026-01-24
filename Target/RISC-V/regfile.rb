module SimInfra
    class XReg
        attr_reader :name
        def initialize(name)
            @name = name
        end

        # String representation for asm output
        def to_s
            @name.to_s
        end
    end

    def XReg(name); XReg.new(name); end

    class XImm
        attr_reader :name
        def initialize(name)
            @name = name
        end

        def to_s
            @name.to_s
        end

        def to_i(base)
            @name.to_s.to_i(base)
        end
    end

    def XImm(name); XImm.new(name); end
end
