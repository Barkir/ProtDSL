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
            srai:  [0x5], # TODO: can be bugs here imm[5:11]  = 0x20
            slti:  0x2,
            sltiu: 0x3,
        }[name]
        format_i(0b0010011, funct3, rd, rs1, imm)
    end

    def format_i_j(name, rd, rs1, imm)
        funct3 =
        {
            jalr: 0x0,
        }[name]
        format_i(0b1100111, funct3, rd, rs1, imm)
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

def format_b(opcode, funct3, rs1, rs2, imm)
    imm_val = imm.is_a?(String) ? imm.to_i(2) : imm.to_i(10)

    # imm[12] | imm[11] | imm[10:5] | imm[4:1]
    #  bit 31    bit 7     30:25      11:8

    imm_12   = (imm_val >> 12) & 0x1     # bit 31
    imm_11   = (imm_val >> 11) & 0x1     # bit 7
    imm_10_5 = (imm_val >> 5)  & 0x3F    # bits 30:25
    imm_4_1  = (imm_val >> 1)  & 0xF     # bits 11:8

    imm_lo = (imm_11 << 4) | imm_4_1
    imm_hi = (imm_12 << 6) | imm_10_5

    return :B, [
        field(:opcode, 6, 0, opcode),
        field(rs1.name, 19, 15, :reg),
        field(rs2.name, 24, 20, :reg),
        field(:funct3, 14, 12, funct3),
        field(:imm, 11, 7, imm_lo),
        field(:imm1, 31, 25, imm_hi)
    ]
end

def format_b_branch(name, rs1, rs2, imm)
    funct3 = {
        beq:  0x0,
        bne:  0x1,
        blt:  0x4,
        bge:  0x5,
        bltu: 0x6,
        bgeu: 0x7
    }[name]
    format_b(0b1100011, funct3, rs1, rs2, imm)
end

    def format_u(opcode, rd, imm)
        imm_val = imm.is_a?(String) ? imm.to_i(2) : imm.to_i(10)

        return :U, [
            field(:opcode, 6, 0, opcode),
            field(rd.name, 11, 7, :reg),
            field(:imm, 31, 12, imm_val & 0xFFFFF)
        ]
    end

    def format_j(opcode, rd, imm)
        imm_val = imm.is_a?(String) ? imm.to_i(2) : imm.to_i(10)

        imm_19_12 = (imm_val >> 12) & 0xFF      # bits 19:12 -> imm [19:12]
        imm_11    = (imm_val >> 11) & 0x1       # bit 11 -> bit 20
        imm_10_1  = (imm_val >> 1)  & 0x3FF     # bits 10:1 -> bits 30:21
        imm_20    = (imm_val >> 20) & 0x1       # bit 20 -> bit 31

        imm_hi = (imm_20 << 11) | (imm_10_1 << 1) | imm_11

        return :J, [
            field(:opcode, 6, 0, opcode),
            field(rd.name, 11, 7, :reg),
            field(:imm, 19, 12, imm_19_12),
            field(:imm1, 31, 20, imm_hi)
        ]
    end

    def format_u_upper(name, rd, imm)
        opcode = {
            lui:   0b0110111,
            auipc: 0b0010111
            }[name]

        format_u(opcode, rd, imm)
    end

    def format_j_jump(name, rd, imm)
        format_j(0b1101111, rd, imm) if name == :jal
    end

end
