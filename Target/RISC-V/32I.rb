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
        asm {"#{name} #{rd}, #{rs1}, #{rs2}"}
        code {rd[]= rs1.send(name, rs2)}
    }
end

I_TYPE_ALU.each do |name|
    Instruction(name, XReg(:rd), XReg(:rs1), XImm(:imm)) {
        encoding *format_i_alu(name, rd, rs1, imm)
        asm {"#{name} #{rd}, #{rs1}, #{imm}"}
        code {rd[]= rs1.send(name, imm)}
    }
end

I_TYPE_LOAD.each do |name|
    Instruction(name, XReg(:rd), XReg(:rs1), XImm(:imm)) {
        encoding *format_i_load(name, rd, rs1, imm)
        asm {"#{name} #{rd}, #{rs1}, #{imm}"}
        code {rd[]= rs1.send(name, imm)}
    }
end

I_TYPE_E.each do |name|
    Instruction(name) {
        encoding *format_i_e(name)
        asm {"#{name}"}
        code { special(name) }
    }
end

S_TYPE.each do |name|
    Instruction(name, XReg(:rs1), XReg(:rs2), XImm(:imm)) {
        encoding *format_s_store(name, rs1, rs2, imm)
        asm {"#{name} #{rs1}, #{rs2}, #{imm}"}
        code {rs1[]= rs2.send(name, imm)} # TODO: change to memory
    }
end

end
