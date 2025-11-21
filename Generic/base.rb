# Testing infra
require_relative "constants"

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

    def self.write_encoder_header(encoder)
        encoder.write(CLASS_MICROASM)
        encoder.write(INITIALIZE_CODE)
        encoder.write(PROG_CODE)
        encoder.write(SET_BITS_CODE)
        encoder.write(SAVE_BINARY_CODE)
        encoder.write(RUN_BINARY_CODE)
    end

    def self.create_encoder(msg=nil)
        encoder = File.open("encoder.rb", "w")
        write_encoder_header(encoder)


        @@instructions.each do |instr|
            print instr
            encoder.write("def translate" + instr.name.to_s + "(#{OPERANDS_ARRAY})\n")
            encoder.write("\tcommand = 0\n")
            instr.fields.each_with_index do |elem, index|
                encoder.write("\t#{elem.name}=#{OPERANDS_ARRAY}[#{index}]\n")
                encoder.write("\tcommand = set_bits(command, #{elem.name}, #{elem.from}, #{elem.to})\n")
            end
            encoder.write(END_TERM)
        end
        encoder.write(END_TERM)
        encoder.close()
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
