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



###############################################
#!SECTION   I-TYPE INSTRUCTIONS               #
###############################################
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

# TODO: debug
I_TYPE_J.each do |name|
    Instruction(name, XReg(:rd), XReg(:rs1), XImm(:imm)) {
        encoding *format_i_j(name, rd, rs1, imm)
        asm {"#{name} #{rd}, #{rs1}, #{imm}"}
        code {rd[]= rs1.send(name, imm)}
    }
end


###############################################
#!SECTION   S-TYPE INSTRUCTIONS               #
###############################################
S_TYPE.each do |name|
    Instruction(name, XReg(:rs1), XReg(:rs2), XImm(:imm)) {
        encoding *format_s_store(name, rs1, rs2, imm)
        asm {"#{name} #{rs1}, #{rs2}, #{imm}"}
        code {rs1[]= rs2.send(name, imm)} # TODO: change to memory
    }
end

# TODO: needs debug
###############################################
#!SECTION   B-TYPE INSTRUCTIONS               #
###############################################
B_TYPE.each do |name|
    Instruction(name, XReg(:rs1), XReg(:rs2), XImm(:imm)) {
        encoding *format_b_branch(name, rs1, rs2, imm)
        asm {"#{name} #{rs1}, #{rs2}, #{imm}"}
        code {
            cond = rs1.send(name, rs2)
            next_pc = cond ? imm : 4
        }
    }
end

# TODO: needs debug
###############################################
#!SECTION   U-TYPE INSTRUCTIONS               #
###############################################
U_TYPE.each do |name|
    Instruction(name, XReg(:rd), XImm(:imm)) {
        encoding *format_u_upper(name, rd, imm)
        asm {"#{name} #{rd}, #{imm}"}
        code {

            # lui: rd = imm << 12
            # auipc: rd = pc + (imm << 12)

            upper = imm << 12

            if name == :lui
                rd[]= upper
            else
                rd[]= upper
            end
        }
    }
end


# TODO: needs debug
###############################################
#!SECTION   J-TYPE INSTRUCTIONS               #
###############################################
J_TYPE.each do |name|
    Instruction(name, XReg(:rd), XImm(:imm)) {
        encoding *format_j_jump(name, rd, imm)
        asm {"#{name} #{rd}, #{imm}"}
        code {

            # jal: rd = pc + 4, pc = pc + imm (21-bit signed offset)
            rd[]= imm

        }
    }
end

end
