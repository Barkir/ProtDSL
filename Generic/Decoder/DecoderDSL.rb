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

        "\t#{reg_to_load.name} = spu.regs[getField(command, #{reg_to_get.to}, #{reg_to_get.from}, #{create_mask(reg_to_get.to, reg_to_get.from)})];\n"
        # \t//#{reg_to_load.name}_name = getField(command, #{reg_to_get.to}, #{reg_to_get.from}, #{create_mask(reg_to_get.to, reg_to_get.from)});\n"
    end

    self.add_instruction :setreg do |irstmt, operands|
        reg_to_load = operands[irstmt.oprnds[0].to_s]
        reg_to_get  = operands[irstmt.oprnds[1].to_s]
        "\tspu.regs[getField(command, #{reg_to_load.to}, #{reg_to_load.from}, #{create_mask(reg_to_load.to, reg_to_load.from)})] = #{reg_to_get.name};\n"
    end

    self.add_instruction :getimm do |irstmt, operands|
        imm_to_get = operands[irstmt.oprnds[0].to_s]

        "\t#{imm_to_get.name} = getField(command, #{imm_to_get.to}, #{imm_to_get.from}, #{create_mask(imm_to_get.to, imm_to_get.from)}); // get_imm\n"
    end

    self.add_instruction :add do |irstmt, operands|
        "\t#{irstmt.oprnds[0].name} = #{irstmt.oprnds[1].name} + #{irstmt.oprnds[2].name}; //\t\t\tadd\n"
    end

    self.add_instruction :sub do |irstmt, operands|
        "\t#{irstmt.oprnds[0].name} = #{irstmt.oprnds[1].name} - #{irstmt.oprnds[2].name}; //\t\t\tsub\n"
    end

    self.add_instruction :let do |irstmt, operands|
        "\t#{irstmt.oprnds[0].name} = #{irstmt.oprnds[1].name}; //\tlet\n"
    end

    self.add_instruction :new_var do |irstmt, operands|
        "\tuint32_t #{irstmt.oprnds[0].name} = 0; //\tnew_var\n"
    end

    self.add_instruction :srl do |irstmt, operands|
        "\t#{irstmt.oprnds[0].name} = #{irstmt.oprnds[1].name} >> #{irstmt.oprnds[2].name}; //\t\t\tsrl\n"
    end

    self.add_instruction :sll do |irstmt, operands|
        "\t#{irstmt.oprnds[0].name} = #{irstmt.oprnds[1].name} << #{irstmt.oprnds[2].name}; //\t\t\tsll\n"
    end

    self.add_instruction :or do |irstmt, operands|
        "\t#{irstmt.oprnds[0].name} = #{irstmt.oprnds[1].name} | #{irstmt.oprnds[2].name}; //\t\t\tor\n"
    end

    self.add_instruction :and do |irstmt, operands|
        "\t#{irstmt.oprnds[0].name} = #{irstmt.oprnds[1].name} & #{irstmt.oprnds[2].name}; //\t\t\tand\n"
    end

    self.add_instruction :xor do |irstmt, operands|
        "\t#{irstmt.oprnds[0].name} = #{irstmt.oprnds[1].name} ^ #{irstmt.oprnds[2].name}; //\t\t\txor\n"
    end

    self.add_instruction :slt do |irstmt, operands|
        "\t#{irstmt.oprnds[0].name} = (#{irstmt.oprnds[1].name} < #{irstmt.oprnds[2].name})?1:0; //\t\t\tslt\n"
    end

    self.add_instruction :sltu do |irstmt, operands|
        "\t#{irstmt.oprnds[0].name} = (#{irstmt.oprnds[1].name} < #{irstmt.oprnds[2].name})?1:0; //\t\t\tsltu\n"
    end

    self.add_instruction :addi do |irstmt, operands|
        "\t#{irstmt.oprnds[0].name} = (#{irstmt.oprnds[1].name} + #{irstmt.oprnds[2].name});     //\t\t\taddi\n"
    end

    self.add_instruction :sra do |irstmt, operands|
    "\t#{irstmt.oprnds[0].name} = (uint32_t)((int32_t)#{irstmt.oprnds[1].name} >> #{irstmt.oprnds[2].name}); //\t\tsra\n"
        end

    self.add_instruction :srai do |irstmt, operands|
      "\t#{irstmt.oprnds[0].name} = (uint32_t)((int32_t)#{irstmt.oprnds[1].name} >> #{irstmt.oprnds[2].name}); //\t\tsrai\n"
    end

    self.add_instruction :beq do |irstmt, operands|
      "\tif (#{irstmt.oprnds[0].name} == #{irstmt.oprnds[1].name}) pc_next = pc + #{irstmt.oprnds[2].name}; //\tbeq\n"
    end

    self.add_instruction :bne do |irstmt, operands|
      "\tif (#{irstmt.oprnds[0].name} != #{irstmt.oprnds[1].name}) pc_next = pc + #{irstmt.oprnds[2].name}; //\tbne\n"
    end

    self.add_instruction :blt do |irstmt, operands|
      "\tif ((int32_t)#{irstmt.oprnds[0].name} < (int32_t)#{irstmt.oprnds[1].name}) pc_next = pc + #{irstmt.oprnds[2].name}; //\tblt\n"
    end

    self.add_instruction :bge do |irstmt, operands|
      "\tif ((int32_t)#{irstmt.oprnds[0].name} >= (int32_t)#{irstmt.oprnds[1].name}) pc_next = pc + #{irstmt.oprnds[2].name}; //\tbge\n"
    end

    self.add_instruction :bltu do |irstmt, operands|
      "\tif (#{irstmt.oprnds[0].name} < #{irstmt.oprnds[1].name}) pc_next = pc + #{irstmt.oprnds[2].name}; //\tbltu\n"
    end

    self.add_instruction :bgeu do |irstmt, operands|
      "\tif (#{irstmt.oprnds[0].name} >= #{irstmt.oprnds[1].name}) pc_next = pc + #{irstmt.oprnds[2].name}; //\tbgeu\n"
    end

    self.add_instruction :jal do |irstmt, operands|
      "\t#{irstmt.oprnds[0].name} = pc + 4; // сохраняем адрес возврата\n
      \tpc_next = pc + #{irstmt.oprnds[1].name}; // переходим\n"
    end

    self.add_instruction :jalr do |irstmt, operands|
      "\tuint32_t t = pc + 4;\n
      \tpc_next = (#{irstmt.oprnds[1].name} + #{irstmt.oprnds[2].name}) & ~1; // lowest bit = 0\n
      \t#{irstmt.oprnds[0].name} = t; // сохраняем адрес возврата\n"
    end

    self.add_instruction :lui do |irstmt, operands|
      "\t#{irstmt.oprnds[0].name} = #{irstmt.oprnds[1].name} << 12; //\tlui\n"
    end

    self.add_instruction :auipc do |irstmt, operands|
      "\t#{irstmt.oprnds[0].name} = pc + (#{irstmt.oprnds[1].name} << 12); //\tauipc\n"
    end

    self.add_instruction :lb do |irstmt, operands|
      "\tint32_t addr = #{irstmt.oprnds[1].name} + #{irstmt.oprnds[2].name};\n
      \tint8_t byte = spu.memory_read_int8(addr);\n
      \t#{irstmt.oprnds[0].name} = (uint32_t)(int32_t)byte; // signed extension\n"
    end

    self.add_instruction :lh do |irstmt, operands|
      "\tint32_t addr = #{irstmt.oprnds[1].name} + #{irstmt.oprnds[2].name};\n
      \tint16_t half = spu.memory_read_int16(addr);\n
      \t#{irstmt.oprnds[0].name} = (uint32_t)(int32_t)half; // signed extension\n"
    end

    self.add_instruction :lw do |irstmt, operands|
      "\tint32_t addr = #{irstmt.oprnds[1].name} + #{irstmt.oprnds[2].name};\n
      \t#{irstmt.oprnds[0].name} = spu.memory_read_uint32(addr);\n"
    end

    self.add_instruction :lbu do |irstmt, operands|
      "\tint32_t addr = #{irstmt.oprnds[1].name} + #{irstmt.oprnds[2].name};\n
      \t#{irstmt.oprnds[0].name} = spu.memory_read_uint8(addr); // unsigned extension\n"
    end

    self.add_instruction :lhu do |irstmt, operands|
      "\tint32_t addr = #{irstmt.oprnds[1].name} + #{irstmt.oprnds[2].name};\n
      \t#{irstmt.oprnds[0].name} = spu.memory_read_uint16(addr); // unsigned extension\n"
    end

    self.add_instruction :sb do |irstmt, operands|
      "\tint32_t addr = #{irstmt.oprnds[0].name} + #{irstmt.oprnds[2].name};\n
      \tspu.memory_write_uint8(addr, #{irstmt.oprnds[1].name});\n"
    end

    self.add_instruction :sh do |irstmt, operands|
      "\tint32_t addr = #{irstmt.oprnds[0].name} + #{irstmt.oprnds[2].name};\n
      \tspu.memory_write_uint16(addr, #{irstmt.oprnds[1].name});\n"
    end

    self.add_instruction :sw do |irstmt, operands|
      "\tint32_t addr = #{irstmt.oprnds[0].name} + #{irstmt.oprnds[2].name};\n
      \tspu.memory_write_uint32(addr, #{irstmt.oprnds[1].name});\n"
    end

    self.add_instruction :ecall do |irstmt, operands|
      <<~CODE
        \t// Обработка системного вызова
        \tuint32_t syscall_num = spu.regs[17]; // a7
        \tuint32_t arg1 = spu.regs[10]; // a0
        \tuint32_t arg2 = spu.regs[11]; // a1
        \tuint32_t arg3 = spu.regs[12]; // a2
        \t
        \t// Здесь должна быть реализация обработки системного вызова
        \t// spu.regs[10] = handle_syscall(syscall_num, arg1, arg2, arg3);
        \t
        \t// Увеличиваем PC
        \tpc_next = pc + 4;
      CODE
    end

    self.add_instruction :ebreak do |irstmt, operands|
      <<~CODE
        \t// Точка останова - обычно вызывает исключение отладчика
        \tspu.breakpoint = true;
        \t// Можно также установить флаг trap
        \t// trap = true;
        \t// trap_cause = BREAKPOINT;
      CODE
    end

    self.add_instruction :andi do |irstmt, operands|
      "\t#{irstmt.oprnds[0].name} = #{irstmt.oprnds[1].name} & #{irstmt.oprnds[2].name}; //\t\t\tandi\n"
    end

    self.add_instruction :xori do |irstmt, operands|
      "\t#{irstmt.oprnds[0].name} = #{irstmt.oprnds[1].name} ^ #{irstmt.oprnds[2].name}; //\t\t\txori\n"
    end

    self.add_instruction :ori do |irstmt, operands|
      "\t#{irstmt.oprnds[0].name} = #{irstmt.oprnds[1].name} | #{irstmt.oprnds[2].name}; //\t\t\tori\n"
    end

    self.add_instruction :slli do |irstmt, operands|
      "\t#{irstmt.oprnds[0].name} = #{irstmt.oprnds[1].name} << #{irstmt.oprnds[2].name}; //\t\t\tslli\n"
    end

    self.add_instruction :srli do |irstmt, operands|
      "\t#{irstmt.oprnds[0].name} = #{irstmt.oprnds[1].name} >> #{irstmt.oprnds[2].name}; //\t\t\tsrli\n"
    end

    self.add_instruction :slti do |irstmt, operands|
      "\t#{irstmt.oprnds[0].name} = ((int32_t)#{irstmt.oprnds[1].name} < (int32_t)#{irstmt.oprnds[2].name}) ? 1 : 0; //\t\tslti\n"
    end

    self.add_instruction :sltiu do |irstmt, operands|
      "\t#{irstmt.oprnds[0].name} = (#{irstmt.oprnds[1].name} < #{irstmt.oprnds[2].name}) ? 1 : 0; //\t\tsltiu\n"
    end
end
end
