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
    def self.write_decoder_header(decoder)
        decoder.write(GET_FIELD_CODE)
        decoder.write(MEMORY_STRUCT_CODE)
        decoder.write(SPU_STRUCT_CODE)
        decoder.write(GET_COMMANDS_CODE)

    end

    def self.create_mask(from, to) # from < to
        "0b" + "0" * (32 - (to - from + 1)) + "1" * (to - from + 1)
    end

    def self.getOperandsAsHashTable(instr)
        operands = instr.fields.select{|f| f.value == :reg}
        .each_with_object({}){|f, h| h[f.name.to_s] = f}
        return operands
    end

    def self.write_ir(decoder, irstmt, operands)
        case irstmt.name.to_s
            when "getreg"
                reg_to_load = operands[irstmt.oprnds[0].to_s]
                reg_to_get = operands[irstmt.oprnds[1].to_s]
                decoder.write("\t#{reg_to_load.name} = spu.regs[getField(command, #{reg_to_get.to}, #{reg_to_get.from}, #{create_mask(reg_to_get.to, reg_to_get.from)})];\n")

            when "setreg"
                reg_to_load = operands[irstmt.oprnds[0].to_s]
                reg_to_get  = operands[irstmt.oprnds[1].to_s]
                decoder.write("\tspu.regs[getField(command, #{reg_to_load.to}, #{reg_to_load.from}, #{create_mask(reg_to_load.to, reg_to_load.from)})] = #{reg_to_get.name};\n")

            when "add"
                decoder.write("\t#{irstmt.oprnds[0].name} = #{irstmt.oprnds[1].name} + #{irstmt.oprnds[2].name};\n")

            when "sub"
                decoder.write("\t#{irstmt.oprnds[0].name} = #{irstmt.oprnds[1].name} - #{irstmt.oprnds[2].name};\n")

            when "let"
                decoder.write("\t#{irstmt.oprnds[0].name} = #{irstmt.oprnds[1].name};\n");

            when "new_var"
                decoder.write("\tint32_t #{irstmt.oprnds[0].name} = 0;\n")

            else
                print irstmt
            end
    end

    def self.create_main(decoder)
        decoder.write(MAIN_CODE)
    end

    def self.create_init(decoder)

    end

    def self.create_decoder
        decoder = File.open("decoder.cpp", "w")
        write_decoder_header(decoder)

        @@instructions.each do |instr|
        decoder.write("void execute#{instr.name}(SPU& spu, uint32_t command) {\n")
        operands = getOperandsAsHashTable(instr)
        instr.code.instance_variable_get(:@tree).each do |irstmt|
            write_ir(decoder, irstmt, operands)
        end
        decoder.write("}\n")
        end
        create_init(decoder)
        create_main(decoder)
    end
end
