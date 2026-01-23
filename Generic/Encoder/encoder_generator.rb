require_relative "constants_encoder.rb"

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
  print "creating function for encoder <<< ", instr, "\n\n\n\n"

  args = instr.fields
    .select { |f| f.value == :reg or f.name == :imm}
    .map(&:name)

  encoder.write("def #{instr.name}(#{args.join(', ')})\n")
  encoder.write("\tskip_if_collect do\n")

  encoder.write("\t\twrite_command(translate#{instr.name}([\n")

  instr.fields.each do |f|
    if f.value == :reg
      encoder.write("\t\t\t#{f.name},\n")
    else
      encoder.write("\t\t\t#{f.value},\n")
    end
  end

  encoder.write("\t\t]))\n")
  encoder.write("\tend\n")
  encoder.write("end\n\n")
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
