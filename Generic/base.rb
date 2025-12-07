# Testing infra
require_relative "constants_encoder"
require_relative "constants_decoder"

module SimInfra
    # @@instructions -array of instruction description
    # shows result of our tests in interactive Ruby (IRB) or standalone
    def self.serialize(msg= nil)
        return @@instructions if Object.const_defined?(:IRB)
        require 'yaml'
        yaml_data = YAML.dump(@@instructions.map(&:to_h))
        File.open("IR.yaml", "w") do |file|
            file.write(yaml_data)
        end
    end

    # reset state
    def siminfra_reset_module_state; @@instructions = []; end

    # mixin for global counter, function returns 0,1,2,....
    module GlobalCounter
        @@counter = -1
        def next_counter; @@counter += 1; end
    end

    Field = Struct.new(:name, :from, :to, :value)
    ImmFieldPart = Struct.new(:name, :from, :to, :hi, :lo)

    def field(name, from, to, value = nil)
        Field.new(name, from, to, value).freeze
    end
    def immpart(name, from, to, hi, lo)
        ImmFieldPart.new(name, from, to, hi, lo).freeze
    end

    def assert(condition, msg = nil); raise msg if !condition; end
end


# ==============================================
# Encoder
# ==============================================

module SimInfra
    def self.write_encoder_header(encoder)

        encoder.write(FISH_CHAIN)
        encoder.write("\# Encoder Standard library functions block\n")
        encoder.write(FISH_CHAIN)

        # those are the header functions
        encoder.write(CLASS_MICROASM)
        encoder.write(INITIALIZE_CODE)
        encoder.write(PROG_CODE)
        encoder.write(SET_BITS_CODE)
        encoder.write(SAVE_BINARY_CODE)
        encoder.write(RUN_BINARY_CODE)
        encoder.write(WRITE_COMMAND_CODE)
        encoder.write(LABEL_CODE)
        encoder.write(SKIP_IF_COLLECT_CODE)

        encoder.write(FISH_CHAIN)

    end

    def self.create_translate_func(encoder, instr)
        encoder.write("def translate#{instr.name.to_s}(#{OPERANDS_ARRAY})\n")
        encoder.write("\tcommand = 0\n")
        instr.fields.each_with_index do |elem, index|
            encoder.write("\t#{elem.name}=#{OPERANDS_ARRAY}[#{index}]\n")
            encoder.write("\tcommand = set_bits(command, #{elem.name}, #{elem.from}, #{elem.to})\n")
        end
        encoder.write("\treturn command\n")
        encoder.write(END_TERM)
        encoder.write("\n\n")
    end

    def self.create_func(encoder, instr)
        operands = instr.fields.select{|f| f.value == :reg}.map(&:name).join(", ")
        opcodes  = instr.fields.select{|f| f.value != :reg}.map(&:value).join(", ")
        encoder.write("def #{instr.name}(#{operands})\n")
            encoder.write("\tskip_if_collect do\n")
            encoder.write("\twrite_command(translate#{instr.name}([#{operands}, #{opcodes}]))\n")
            encoder.write("\t" + END_TERM)
        encoder.write(END_TERM)
        encoder.write("\n\n")
    end

    def self.create_encoder(msg=nil)
        encoder = File.open("encoder.rb", "w")
        write_encoder_header(encoder)

        @@instructions.each do |instr|

            encoder.write(EQUAL_CHAIN)
            encoder.write("\# #{instr.name} functions block\n")
            encoder.write(EQUAL_CHAIN)
            create_func(encoder, instr)
            create_translate_func(encoder, instr)
            encoder.write(EQUAL_CHAIN)
        end
        encoder.write(END_TERM)
        encoder.close()
    end
end

# ==============================================
# Decoder
# ==============================================
module SimInfra
   class DecoderDSL
        class << self


        def create_mask(from, to) # from < to
            "0b" + "0" * (32 - (to - from + 1)) + "1" * (to - from + 1)
        end

            def add_instruction(name, &tmpl)
                instructions[name.to_s] = tmpl
            end

            def instructions
                @instructions ||= {}
            end


            def write_ir(decoder, irstmt, operands)
                template = instructions[irstmt.name.to_s]
                if template
                    decoder.write(template.call(irstmt, operands))
                end
            end

        end

        self.add_instruction :getreg do |irstmt, operands|
            reg_to_load = operands[irstmt.oprnds[0].to_s]
            reg_to_get = operands[irstmt.oprnds[1].to_s]
            "\t#{reg_to_load.name} = spu.regs[getField(command, #{reg_to_get.to}, #{reg_to_get.from}, #{create_mask(reg_to_get.to, reg_to_get.from)})];\n"
        end

        self.add_instruction :setreg do |irstmt, operands|
            reg_to_load = operands[irstmt.oprnds[0].to_s]
            reg_to_get  = operands[irstmt.oprnds[1].to_s]
            "\tspu.regs[getField(command, #{reg_to_load.to}, #{reg_to_load.from}, #{create_mask(reg_to_load.to, reg_to_load.from)})] = #{reg_to_get.name};\n"
        end

        self.add_instruction :add do |irstmt, operands|
            "\t#{irstmt.oprnds[0].name} = #{irstmt.oprnds[1].name} + #{irstmt.oprnds[2].name};\n"
        end

        self.add_instruction :sub do |irstmt, operands|
            "\t#{irstmt.oprnds[0].name} = #{irstmt.oprnds[1].name} - #{irstmt.oprnds[2].name};\n"
        end

        self.add_instruction :let do |irstmt, operands|
            "\t#{irstmt.oprnds[0].name} = #{irstmt.oprnds[1].name};\n"
        end

        self.add_instruction :new_var do |irstmt, operands|
            "\tint32_t #{irstmt.oprnds[0].name} = 0;\n"
        end

    end

    def self.write_decoder_header(decoder)
        decoder.write(REGULAR_HEADER_CODE)
        decoder.write(GET_FILE_SIZE_CODE)
        decoder.write(GET_FIELD_CODE)
        decoder.write(MEMORY_STRUCT_CODE)
        decoder.write(SPU_STRUCT_CODE)
        decoder.write(GET_COMMANDS_CODE)
        decoder.write(GET_COMMAND_CODE)

    end

    def self.create_mask(from, to) # from < to
        "0b" + "0" * (32 - (to - from + 1)) + "1" * (to - from + 1)
    end

    def self.getOperandsAsHashTable(instr)
        operands = instr.fields.select{|f| f.value == :reg}
        .each_with_object({}){|f, h| h[f.name.to_s] = f}
        return operands
    end

    def self.create_main(decoder)
        decoder.write(MAIN_CODE)
    end

    def self.generate_switch(decoder, subtree, level)
            key = subtree.keys[0]
            decoder.write("\t" * level + "int field_level#{level} = getField(command, #{key[:from]}, #{key[:to]}, #{create_mask(key[:from], key[:to])});\n")
            decoder.write("\t" *  level + "switch(field_level#{level}) {\n")
            for key in subtree.keys
                decoder.write("\t" * level + "case #{key[:value]}:\n", "\t" * level, "{\n")
                if subtree[key].is_a?(Hash)
                    generate_switch(decoder, subtree[key], level + 1)
                else
                    decoder.write("\t" * level + "execute#{subtree[key].to_s}(spu, command);\n")
                end
                    decoder.write("\t" * level + "break;}\n")
            end
            decoder.write("\t" * level + "}\n")
    end

    def self.create_init(decoder)
        decoder.write(INIT_HEADER_CODE)
        generate_switch(decoder, @tree, 2)
        decoder.write("\t}\n")
        decoder.write("}\n")

    end

    def self.create_decoder
        decoder = File.open("decoder.cpp", "w")
        write_decoder_header(decoder)

        create_decoding_tree()

        @@instructions.each do |instr|
        decoder.write("void execute#{instr.name}(SPU& spu, uint32_t command) {\n")
        operands = getOperandsAsHashTable(instr)
        instr.code.instance_variable_get(:@tree).each do |irstmt|
            DecoderDSL.write_ir(decoder, irstmt, operands)
        end

        print("OOOPERANDS = ", operands.to_s)
        decoder.write("\tstd::cout << \"#{instr.name} \\t \" #{operands.keys.map{|k| ["<<" + '"' + k.to_s + '="' + "<<" + k.to_s]}.join("<< \" \t \"")} <<\":\" << std::hex << \"\t\t\" << command << std::dec << std::endl;\n")
        decoder.write("\tspu.pc += PC_INC;\n")
        decoder.write("}\n")
        end
        # print @@instructions
        create_init(decoder)
        create_main(decoder)
    end
end

# {51 => {0 => {0 => {ADD}, 4 => {XOR}, 6 => {OR}}, 32 => {0 => {SUB}}}}

module SimInfra

    def self.dump_tree(tree, filename = "tree.dot")
    File.open(filename, "w") do |f|
        f.write "digraph {\n"
        f.write "  node [shape=box];\n"
        dump_hash_node(f, tree, "root")
        f.write "}\n"
    end

    system("dot -Tpng #{filename} -o #{filename.sub('.dot', '.png')}")
    end

def self.dump_hash_node(file, value, node_id)
  if value.is_a?(Hash)
    keys_label = value.keys.map do |k|
      if k.is_a?(Array) && k.first.is_a?(Hash) && k.first.key?(:value)
        "⟨#{k.first[:value]}⟩"
      else
        k.inspect
      end
    end.join("\\n")

    file.write "  #{node_id} [label=\"#{node_id}\\nKeys:\\n#{keys_label}\"];\n"

    value.each_with_index do |(key, subvalue), idx|
      child_id = "#{node_id}_key#{idx}"

      if key.is_a?(Array) && key.first.is_a?(Hash) && key.first.key?(:value)
        edge_label = "⟨#{key.first[:value]}⟩"
      else
        edge_label = key.inspect.gsub(/"/, '\\"')
      end

      file.write "  #{node_id} -> #{child_id} [label=\"#{edge_label}\"];\n"
      dump_hash_preorder(file, subvalue, child_id)
    end
  else
    escaped_value = value.inspect.gsub(/"/, '\\"').gsub(/\n/, '\\n')
    file.write "  #{node_id} [label=\"#{node_id}\\n#{escaped_value}\", shape=ellipse];\n"
  end
end

def self.dump_hash_preorder(file, value, node_id)
  if value.is_a?(Hash)
    value.each_with_index do |(k, v), idx|
      child_id = "#{node_id}_#{idx}"
      if v.is_a?(Hash)
        key_label = if k.is_a?(Array) && k.first.is_a?(Hash) && k.first.key?(:value)
                      "⟨#{k.first[:value]}⟩"
                    else
                      k.inspect
                    end
        file.write "  #{child_id} [label=\"#{key_label}\"];\n"
        file.write "  #{node_id} -> #{child_id};\n"
        dump_hash_preorder(file, v, child_id)
      else
        escaped_k = k.inspect.gsub(/"/, '\\"')
        escaped_v = v.inspect.gsub(/"/, '\\"')
        file.write "  #{child_id} [label=\"#{escaped_k} = #{escaped_v}\", shape=ellipse];\n"
        file.write "  #{node_id} -> #{child_id};\n"
      end
    end
  else
    escaped_value = value.inspect.gsub(/"/, '\\"').gsub(/\n/, '\\n')
    file.write "  #{node_id} [label=\"#{escaped_value}\", shape=ellipse];\n"
  end
end

    def self.build_decoding_tree(tree, instruction_map, depth=0)
        print "----------------------------------------------------------\n"
        print "tree = ", @tree.to_s, " map = ", instruction_map.to_s + "\n"
        if instruction_map.size == 1
            print "keys.first = " + instruction_map.keys.first.to_s + "\n"
            return instruction_map.keys.first
        end
        first_values = instruction_map.values.first
        if depth >= first_values.length
            raise "Impossible to recognize instructions #{instruction_map.keys}"
        end

        groups = Hash.new {|h, k| h[k] = {} }
        instruction_map.each do |name, values|
            key = values[depth]
            groups[key][name] = values
        end
        print "groups = ", groups.to_s + "\n"
        for key in groups.keys
            tree[key] = Hash.new {|h, k| h[k] = {}}
            tree[key] = build_decoding_tree(tree[key], groups[key], depth+1)
        end
        return tree
        print @tree.to_s + "\n"
    end

    def self.create_decoding_tree()
        @tree = Hash.new {|h, k| h[k] = {}}
        instruction_map = {}
        @@instructions.each do |instr|
            neededFields = instr.fields.select{|f| f.value.is_a?(Numeric)}.map{|f| {:value => f.value, :from => f.to, :to => f.from}}
            print neededFields
            instruction_map[instr.name] = neededFields
        end
        print "\n"
        build_decoding_tree(@tree, instruction_map, 0)
        print @tree.to_s + "\n"
        dump_tree(@tree)
        return @tree
    end
end
