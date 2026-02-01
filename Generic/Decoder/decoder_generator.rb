require_relative "decoder_tree.rb"
require_relative "DecoderDSL.rb"
require_relative "switch.rb"
require_relative "constants_decoder.rb"

require 'yaml'

module SimInfra

    def self.write_decoder_header(decoder)
        decoder.write(REGULAR_HEADER_CODE)
        decoder.write(GET_FILE_SIZE_CODE)
        decoder.write(GET_FIELD_CODE)
        decoder.write(MEMORY_STRUCT_CODE)
        decoder.write(SPU_STRUCT_CODE)
        decoder.write(GET_COMMANDS_CODE)
        decoder.write(GET_COMMAND_CODE)

    end

    def self.create_decoder
        decoders = File.open("src/decoders.hpp", "w")
        decoders.write("#pragma once\n")
        executers = File.open("src/executers.hpp", "w")
        executers.write("#pragma once\n")

        thing = YAML.safe_load(YAML_PATH)

        puts thing.inspect

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

        end
        # print @@instructions
        create_big_switch(executers)
        # create_main(decoder)
    end
end
