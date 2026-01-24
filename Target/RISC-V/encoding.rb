require_relative "../../Generic/base"

module SimInfra
    def format_r(opcode, funct3, funct7, rd, rs1, rs2)
        return :R, [
            field(rd.name, 11, 7, :reg),
            field(rs1.name, 19, 15, :reg),
            field(rs2.name, 24, 20, :reg),
            field(:opcode, 6, 0, opcode),
            field(:funct7, 31, 25, funct7),
            field(:funct3, 14, 12, funct3),
        ]
    end

    def format_i(opcode, funct3, rd, rs1, imm)
        return :I, [
            field(rd.name, 11, 7, :reg),
            field(rs1.name, 19, 15, :reg),
            field(:opcode, 6, 0, opcode),
            field(:imm, 31, 20, imm),
            field(:funct3, 14, 12, funct3),
        ]
    end

    def format_s(opcode, funct3, imm1, imm2, rs1, rs2)
        return :S, [
            field(rs1.name, 19, 15, :reg),
            field(rs2.name, 24, 20, :reg),
            field(:funct3, 14, 12, funct3),
            field(:opcode, 6, 0, opcode),
            field(:imm, 11, 7, imm1),
            field(:imm1, 31, 25, imm2) # TODO: bad formatting
        ]
    end

    def format_s_store(name, rs1, rs2, imm)
        imm1 = (imm.to_i(2).to_s[0..4]).to_i
        imm2 = (imm.to_i(2).to_s[5..11]).to_i
        funct3 =
        {
            sb: 0x0,
            sh: 0x1,
            sw: 0x2
        }[name]
        format_s(0b0100011, funct3, imm1, imm2, rs1, rs2)
    end

    def format_r_alu(name, rd, rs1, rs2)
        funct3, funct7 =
        {
            add: [0, 0],
            sub: [0, 1 << 5],
            xor: [0x4, 0x00],
            or:  [0x6, 0x00],
            and: [0x7, 0x00],
            sll: [0x1, 0x00],
            srl: [0x5, 0x00],
            slt: [0x2, 0x00],
            sltu:[0x3, 0x00]

        }[name]
        format_r(0b0110011, funct3, funct7, rd, rs1, rs2)
    end

    def format_i_alu(name, rd, rs1, imm)
        funct3 =
        {
            addi:  0x0,
            xori:  0x4,
            ori:   0x6,
            andi:  0x7,
            slli:  0x1,
            srli:  0x5,
            # srai:  [0x5], # TODO: can be bugs here imm[5:11]  = 0x20
            slti:  0x2,
            sltiu: 0x3,
        }[name]
        format_i(0b0010011, funct3, rd, rs1, imm)
    end


    def format_i_load(name, rd, rs1, imm)
        funct3 =
        {
            ld: 0x0,
            lh: 0x1,
            lw: 0x2,
            lbu: 0x4,
            lhu: 0x5
        }[name]
        format_i(0b0000011, funct3, rd, rs1, imm)
    end

    def format_i_e(name)
        funct3, imm =
        {
            ecall:  [0x0, 0x0],
            ebreak: [0x0, 0x1]
        }[name]
        return :I, [
            field(:opcode, 6, 0, 0b1110011),
            field(:imm0, 31, 20, imm),
            field(:funct3, 14, 12, funct3)
        ]
    end

    def format_j(name, rd, imm)
    end

end
