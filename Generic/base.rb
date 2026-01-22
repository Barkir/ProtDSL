# Testing infra
require_relative "constants_encoder"
require_relative "constants_decoder"

# ecall, ebreak

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
            "\t#{reg_to_load.name} = spu.regs[getField(command, #{reg_to_get.to}, #{reg_to_get.from}, #{create_mask(reg_to_get.to, reg_to_get.from)})];\n
            \t//#{reg_to_load.name}_name = getField(command, #{reg_to_get.to}, #{reg_to_get.from}, #{create_mask(reg_to_get.to, reg_to_get.from)});\n"
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
            "\tuint32_t #{irstmt.oprnds[0].name} = 0;\n
            \t //uint32_t #{irstmt.oprnds[0].name}_name = -1;\n"
        end

        self.add_instruction :srl do |irstmt, operands|
            "\t#{irstmt.oprnds[0].name} = #{irstmt.oprnds[1].name} >> #{irstmt.oprnds[2].name};\n"
        end

        self.add_instruction :sll do |irstmt, operands|
            "\t#{irstmt.oprnds[0].name} = #{irstmt.oprnds[1].name} << #{irstmt.oprnds[2].name};\n"
        end

        self.add_instruction :or do |irstmt, operands|
            "\t#{irstmt.oprnds[0].name} = #{irstmt.oprnds[1].name} | #{irstmt.oprnds[2].name};\n"
        end

        self.add_instruction :and do |irstmt, operands|
            "\t#{irstmt.oprnds[0].name} = #{irstmt.oprnds[1].name} & #{irstmt.oprnds[2].name};\n"
        end

        self.add_instruction :xor do |irstmt, operands|
            "\t#{irstmt.oprnds[0].name} = #{irstmt.oprnds[1].name} ^ #{irstmt.oprnds[2].name};\n"
        end


        # self.add_instruction

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

    def self.generate_switch(executer, subtree, level)
            key = subtree.keys[0]
            name = generate_get_bits_function(executer, key[1], key[2] + 1)
            # executer.write("\t" * level + "std::cout << \"#{name} = \" << #{name} << std::endl;" + "\n")
            # executer.write("\t" * level + "std::cout << std::bitset<32>(#{name}) << std::endl;" + "\n")
            executer.write("\t" * level + "switch(#{name}) {\n")
            for key in subtree.keys
                executer.write("\t" * level + "case #{key[0]}:\n", "\t" * level, "{\n")
                if subtree[key].is_a?(Hash)
                    generate_switch(executer, subtree[key], level + 1)
                else
                    executer.write("\t" * (level + 1) + "decode#{subtree[key].to_s.tr('[', '').tr(']', '').tr(':', '')}(spu, command);\n")
                    executer.write("\t" * (level + 1) + "execute#{subtree[key].to_s.tr('[', '').tr(']', '').tr(':', '')}(spu, command);\n")
                end
                    executer.write("\t" * (level + 1) + "break;\n" + "\t" * level + "}\n")
            end
            executer.write("\t" * level + "default: break;\n")
            executer.write("\t" * level + "}\n")
    end

    def self.create_big_switch(file)
        # decoder.write(INIT_HEADER_CODE)
        file.write("void inline bigSwitch(SPU& spu, uint32_t command){\n")
        generate_switch(file, @tree, 2)
        file.write("}\n")
    end

    def self.create_decoder
        decoders = File.open("src/decoders.hpp", "w")
        decoders.write("#pragma once\n")
        executers = File.open("src/executers.hpp", "w")
        executers.write("#pragma once\n")

        create_decoding_tree(executers)

        @@instructions.each do |instr|
        executers.write("void inline execute#{instr.name}(SPU& spu, uint32_t command) {\n")
        operands = getOperandsAsHashTable(instr)
        instr.code.instance_variable_get(:@tree).each do |irstmt|
            # print irstmt.to_s + "\n"
            DecoderDSL.write_ir(executers, irstmt, operands)
        end
        executers.write("}\n")

        decoders.write("void inline decode#{instr.name}(SPU& spu, uint32_t command) {\n")
        decoders.write("\tstd::cout << \"#{instr.name} \" << std::endl;\n")
        decoders.write("}\n");


        # decoders.write("\tstd::cout <<
                    # \"#{instr.name} \\t \"
                    #{operands.keys.map{|k| ["<<" + '"' + k.to_s + '="' + "<<" + k.to_s + "_name"]}.join("<< std::setw(8)")}
                    # <<\":\"
                    # << std::right << std::hex <<
                    # std::setw(15) << std::setfill(' ') << command << std::dec << std::endl;\n")
        # decoders.write("}\n")
        end
        # print @@instructions
        create_big_switch(executers)
        # create_main(decoder)
    end
end


############################################################################
############################################################################
# {51 => {0 => {0 => {ADD}, 4 => {XOR}, 6 => {OR}}, 32 => {0 => {SUB}}}}
############################################################################
############################################################################

module SimInfra

    def self.dump_tree(tree, filename = "dot/tree.dot")
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

# score is evaluated using this formula: score = N_total - N_x - |N_0 - N_1|
# N_total - number of instructions where we choose this bit (instruction_map.length)

# N_x - number of instructions where this bit is marked as     'don't care'
# N_0 - number of instructions where this bit is equal to       0
# N_1 - number of instructions where this bit is equal to       1

    def self.getBitScore(instruction_map, nbit)
        n_total = instruction_map.length
        if n_total == 2
            return instruction_map.values[0][nbit][:value] ^ instruction_map.values[1][nbit][:value]
        end
        n_0 = 0
        n_1 = 0
        n_x = 0
        instruction_map.each do |name, value|
            if value[nbit][:type] == 0
                n_x += 1
            elsif value[nbit][:value] == 1
                n_1 += 1
            elsif value[nbit][:value] == 0
                n_0 += 1
            end
        end
        printf("total: %d, don't care: %d, 1: %d, 0: %d\n", n_total, n_x, n_1, n_0)
        return n_total - n_x - (n_0 - n_1).abs
    end

    def self.get_instruction_string(map, bitBasis)
        instructionString = []
        index = 0
        bitBasis.each do |value|
            instructionString[index] = map[value[:nbit]]
            instructionString[index][:nbit] = value[:nbit]
            index += 1
        end
        # puts instructionString
        # puts "\n"

        # turn it into string
        return instructionString.map{|item| item[:value].to_s}.join.rjust(bitBasis.length, '0')
    end

    def self.generate_get_bits_function(executers, bitBasis, depth)
        # executers.write("int getBitsAtLevel#{depth}(uint32_t command) {\n")
            var_name = "bits_#{depth}_#{bitBasis.map{|n| n[:nbit]}.join()}"
            executers.write("\t" * depth + "\tint #{var_name} = 0;\n")
            executers.write("\t" * depth + "\tint bitMask = 0;\n")
            # i need to get the bits and collect them into single number
            # 1. get the value of n'th bit. this can be done by masking it
            # 2. set this bit as the 0, 1, 2 bit in the 'bits' value

            bitBasis.each_with_index do |value, n|
                printf("basis: %d <<< index: %d\n", value[:nbit], n)
                mask = ("1" + "0" * (value[:nbit])).rjust(32, '0')
                print("mask = " + mask + "\n")
                executers.write("\t" * depth + "bitMask = (command & 0b#{mask}) >> #{value[:nbit] - n - (STANDARD_BIT_BASIS_SIZE - 2)};\n")

                # executers.write("\t" * depth + "std::cout << std::bitset<32>(command) << \"\t&\"<< std::endl;\n")
                # executers.write("\t" * depth + "std::cout << std::bitset<32>(0b#{mask}) << std::endl;\n")
                # executers.write("\t" * depth + "std::cout << \"\t\t=\" << std::endl;\n")
                # executers.write("\t" * depth + "std::cout << bitMask << std::endl;\n")

                # executers.write("\t" * depth + "std::cout << std::bitset<32>(#{var_name}) << std::endl;\n")
                # executers.write("\t" * depth + "std::cout << \"\t\t+\" << std::endl;\n")
                # executers.write("\t" * depth + "std::cout << std::bitset<32>(bitMask) << std::endl;\n")
                # executers.write("\t" * depth + "std::cout << \"\t\t=\" << std::endl;\n")

                executers.write("\t" * depth + "\t#{var_name} += bitMask;\n")

                # executers.write("\t" * depth + "std::cout << #{var_name} << std::endl;")

                # executers.write("\t" * depth + "std::cout << \"bit#{value[:nbit]}, offset#{value[:nbit] - n - 1} : \" << \tstd::bitset<32>(#{var_name})" + " << std::endl;\n")
            end
            # executers.write("\treturn bits;\n")
        # executers.write("}\n")
        return var_name
    end

    def self.build_decoding_tree(executers, tree, instruction_map, depth=0)
        printf(":: building a decoding tree at depth %d | %s \n", depth, instruction_map.keys)
        if instruction_map.size == 1
            return instruction_map.keys
        end

        bitRange = Array.new(32) do
            {score: 0, nbit: 0}
        end

        (0..31).each do |i|
            score = getBitScore(instruction_map, i)
            bitRange[i][:score] = score
            bitRange[i][:nbit] = i
        end
        instruction_map.each do |name, value|
            value_clean = value.map {|n| n[:value]}
            print value_clean.join("")
            print "\n"
        end
        printf(":: got bitRange %s \n", bitRange.to_s)
        bitBasis = bitRange.select{|item| item[:score] != 0}.sort_by{|item| -item[:score]}.first(STANDARD_BIT_BASIS_SIZE)
        printf(":: got bitBasis %s at length %d\n", bitBasis.to_s, depth)
        # generate_get_bits_function(executers, bitBasis, depth)
        # iterating from 0 to 1111 (in case if we choose 4 bits as a basis)
        (0..2**bitBasis.length).each do |i|

            # making a string:  e.g. '0101'
            bitString = i.to_s(2).rjust(bitBasis.length, '0')
            sub_instruction_map = {}

            # iterating over instructions to check if bits are equal
            # to bitString and add them to sub_instruction_map
            # then calling build_decoding_tree recursively
            instruction_map.each do |name, map|
                instructionString = get_instruction_string(map, bitBasis)
                printf("%s <><><> %s, %d\n", instructionString, bitString, instructionString == bitString ? 1 : 0)
                if instructionString == bitString
                    sub_instruction_map[name] = map
                end
            end
            print("\n")
            if sub_instruction_map.length > 0
                tree[[bitString.to_i(2), bitBasis, depth]] = Hash.new {|h, k| h[k] = {}}
                tree[[bitString.to_i(2), bitBasis, depth]] = build_decoding_tree(executers, tree[[bitString.to_i(2), bitBasis, depth]], sub_instruction_map, depth+1)
            end
        end
        return tree
    end

    def self.set_bits(number, value, to, from)
    width = to - from + 1
    mask = ((1 << width) - 1) << from
    (number & ~mask) | ((value & ((1 << width) - 1)) << from)
    end

    def self.buildValue(fields)
    bitValue = Array.new(INSTRUCTION_SIZE_IN_BITS) do
        {type: 0, value: 0}
    end
    fields.each do |field|

        strVal = field[:value].to_s(2).rjust(field[:to] - field[:from] + 1, '0')
        index = 0
        (field[:from]...field[:to] + 1).each do |i|
            bitValue[i][:value] = strVal[index].to_i
            bitValue[i][:type] = 1
            index += 1
        end
    end
    # printf("%b\n", retVal)
    return bitValue
    end

    def self.create_decoding_tree(executers)
        @tree = Hash.new {|h, k| h[k] = {}}
        instruction_map = {}
        @@instructions.each do |instr|
            neededFields = instr.fields.select{|f| f.value.is_a?(Numeric)}.map{|f| {:value => f.value, :from => f.to, :to => f.from}}
            fullValues = []
            printf "building value for %s instruction\n", instr.name
            value = buildValue(neededFields)
            instruction_map[instr.name] = value
        end

        # print instruction_map
        # print "\n"
        build_decoding_tree(executers, @tree, instruction_map, 0)
        print @tree.to_s + "\n"
        dump_tree(@tree)
        return @tree
    end
end

