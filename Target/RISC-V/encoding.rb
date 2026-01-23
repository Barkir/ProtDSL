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
            field(:imm1, 11, 7, imm1),
            field(:imm2, 31, 25, imm2)
        ]
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
end
