require_relative "encoding"
require_relative "regfile"
require_relative "../../Generic/base"

# RISCV IM

module RV32I
    extend SimInfra

###############################################
#!SECTION   R-TYPE INSTRUCTIONS               #
###############################################
R_TYPE.each do |name|
    Instruction(name, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
        encoding *format_r_alu(name, rd, rs1, rs2)
        asm {"#{name.to_s.upcase} #{rd}, #{rs1}, #{rs2}"}
        code {rd[]= rs1.send(name, rs2)}
    }
end

I_TYPE.each do |name|
    Instruction(name, XReg(:rd), XReg(:rs1), XImm(:imm)) {
        encoding *format_i_alu(name, rd, rs1, imm)
        asm {"#{name.to_s.upcase} #{rd}, #{rs1}, #{imm}"}
        code {rd[]= rs1.send(name, imm)}
    }
end


#     Instruction(:ADD, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
#         encoding *format_r_alu(:add, rd, rs1, rs2)
#         asm { "ADD #{rd}, #{rs1}, #{rs2}" }
#         code { rd[]= rs1.add rs2 }
#     }
#
#     Instruction(:SUB, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
#         encoding *format_r_alu(:sub, rd, rs1, rs2)
#         asm { "SUB #{rd}, #{rs1}, #{rs2}" }
#         code { rd[]= rs1.sub rs2 }
#     }
#
#     Instruction(:XOR, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
#         encoding *format_r_alu(:xor, rd, rs1, rs2)
#         asm { "XOR #{rd}, #{rs1}, #{rs2}" }
#         code {rd[]= rs1.xor rs2 }
#     }
#
#     Instruction(:OR, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
#         encoding *format_r_alu(:or, rd, rs1, rs2)
#         asm { "OR #{rd}, #{rs1}, #{rs2}"}
#         code{rd[]= rs1.or rs2}
#     }
#
#     Instruction(:AND, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
#         encoding *format_r_alu(:and, rd, rs1, rs2)
#         asm {"AND #{rd}, #{rs1}, #{rs2}" }
#         code {rd[]= rs1.and rs2}
#     }
#     Instruction(:SLL, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
#         encoding *format_r_alu(:sll, rd, rs1, rs2)
#         asm {"SLL #{rd}, #{rs1}, #{rs2}"}
#         code {rd[]=rs1.sll rs2}
#     }
#     Instruction(:SRL, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
#         encoding *format_r_alu(:srl, rd, rs1, rs2)
#         asm {"SLL #{rd}, #{rs1}, #{rs2}"}
#         code {rd[]= rs1.srl rs2}
#     }
#
#     Instruction(:SLT, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
#         encoding *format_r_alu(:slt, rd, rs1, rs2)
#         asm {"SLT #{rd}, #{rs1}, #{rs2}"}
#         code {rd[]= rs1.slt rs2}
#     }
#
#     Instruction(:SLTU, XReg(:rd), XReg(:rs1), XReg(:rs2)) {
#         encoding *format_r_alu(:sltu, rd, rs1, rs2)
#         asm {"SLT #{rd}, #{rs1}, #{rs2}"}
#         code {rd[]= rs1.sltu rs2}
#     }

###############################################
#!SECTION   I-TYPE INSTRUCTIONS               #
###############################################
#     Instruction(:ADDI, XReg(:rd), XReg(:rs1), XImm(:imm)) {
#         encoding *format_i_alu(:addi, rd, rs1, imm)
#         asm {"ADDI #{rd}, #{rs1}, #{imm}"}
#         code {rd[]= rs1.addi imm}
#     }
#
#     Instruction(:XORI, XReg(:rd), XReg(:rs1), XImm(:imm)) {
#         encoding *format_i_alu(:xori, rd, rs1, imm)
#         asm {"XORI #{rd}, #{rs1}, #{imm}"}
#         code {rd[]= rs1.xori imm}
#     }
#
#     Instruction(:ANDI, XReg(:rd), XReg(:rs1), XImm(:imm)) {
#         encoding *format_i_alu(:andi, rd, rs1, imm)
#         asm {"ANDI #{rd}, #{rs1}, #{imm}"}
#         code {rd[]= rs1.andi imm}
#     }
#
#     Instruction(:ORI, XReg(:rd), XReg(:rs1), XImm(:imm)) {
#         encoding *format_i_alu(:ori, rd, rs1, imm)
#         asm {"ORI #{rd}, #{rs1}, #{imm}"}
#         code {rd[]= rs1.ori imm}
#     }

end
