require_relative "constants_decoder"
require_relative "helper.rb"
require_relative "../base.rb"

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

    self.add_instruction :slt do |irstmt, operands|
        "\t#{irstmt.oprnds[0].name} = (#{irstmt.oprnds[1].name} < #{irstmt.oprnds[2].name})?1:0\n;"
    end

    self.add_instruction :sltu do |irstmt, operands|
        "\t#{irstmt.oprnds[0].name} = (#{irstmt.oprnds[1].name} < #{irstmt.oprnds[2].name})?1:0\n;"
    end
end
end
