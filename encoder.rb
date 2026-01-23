# <><><><><><><><><><><><><><><><><><><><><><><>
# Encoder Standard library functions block
# <><><><><><><><><><><><><><><><><><><><><><><>
class MicroAsm
def initialize
    @labels = {}
    @pc = 0
    @commands = []
    @registers = {}

    (0..31).each do |i|
        reg_name = "r#{i}".to_sym
        self.define_singleton_method(reg_name) do
            i
        end
    end
end
def prog(&block)

    # ---------------------------
        @collecting_labels = true
        @pc = 0
        instance_eval(&block)
    # ---------------------------------

        @pc = 0
        @command_pc = 0
        @collecting_labels = false
        instance_eval(&block)

        save_binary
        #run_binary
    end
def set_bits(number, value, to, from)
    width = to - from + 1
    mask = ((1 << width) - 1) << from
    (number & ~mask) | ((value & ((1 << width) - 1)) << from)
end
def save_binary(filename="result.bin")
        File.open(filename, "wb") do |file|
            @commands.each do |elem|
                file.write([elem].pack("L<")) ## little endian
            end
            absolute_path = File.expand_path("result.bin")
            file.close()

            filename

        end
    end
def run_binary(binary_filename="result.bin")
    absolute_path = File.expand_path(binary_filename)
    print absolute_path
    system(TOY_SIM + "toy_interpreter " + absolute_path)
end

def write_command(value)
    @commands[@command_pc] = value

    @pc += 4
    @command_pc += 1
end
def label(label_str)
    raise  "Expected symbol, got #{label_str.class}" unless label_str.is_a?(Symbol)
    if @collecting_labels
        @labels[label_str] = @pc
    end
end
def skip_if_collect(&block)
  if @collecting_labels
    @pc += 4
  else
    yield
  end
end
# <><><><><><><><><><><><><><><><><><><><><><><>
# ==============================================
# add functions block
# ==============================================
def add(rd, rs1, rs2)
	skip_if_collect do
		write_command(translateadd([
			rd,
			rs1,
			rs2,
			51,
			0,
			0,
		]))
	end
end

def translateadd(operands)
	command = 0
	rd=operands[0]
	command = set_bits(command, rd, 11, 7)
	rs1=operands[1]
	command = set_bits(command, rs1, 19, 15)
	rs2=operands[2]
	command = set_bits(command, rs2, 24, 20)
	opcode=operands[3]
	command = set_bits(command, opcode, 6, 0)
	funct7=operands[4]
	command = set_bits(command, funct7, 31, 25)
	funct3=operands[5]
	command = set_bits(command, funct3, 14, 12)
	return command
end


# ==============================================
# ==============================================
# sub functions block
# ==============================================
def sub(rd, rs1, rs2)
	skip_if_collect do
		write_command(translatesub([
			rd,
			rs1,
			rs2,
			51,
			32,
			0,
		]))
	end
end

def translatesub(operands)
	command = 0
	rd=operands[0]
	command = set_bits(command, rd, 11, 7)
	rs1=operands[1]
	command = set_bits(command, rs1, 19, 15)
	rs2=operands[2]
	command = set_bits(command, rs2, 24, 20)
	opcode=operands[3]
	command = set_bits(command, opcode, 6, 0)
	funct7=operands[4]
	command = set_bits(command, funct7, 31, 25)
	funct3=operands[5]
	command = set_bits(command, funct3, 14, 12)
	return command
end


# ==============================================
# ==============================================
# xor functions block
# ==============================================
def xor(rd, rs1, rs2)
	skip_if_collect do
		write_command(translatexor([
			rd,
			rs1,
			rs2,
			51,
			0,
			4,
		]))
	end
end

def translatexor(operands)
	command = 0
	rd=operands[0]
	command = set_bits(command, rd, 11, 7)
	rs1=operands[1]
	command = set_bits(command, rs1, 19, 15)
	rs2=operands[2]
	command = set_bits(command, rs2, 24, 20)
	opcode=operands[3]
	command = set_bits(command, opcode, 6, 0)
	funct7=operands[4]
	command = set_bits(command, funct7, 31, 25)
	funct3=operands[5]
	command = set_bits(command, funct3, 14, 12)
	return command
end


# ==============================================
# ==============================================
# or functions block
# ==============================================
def or(rd, rs1, rs2)
	skip_if_collect do
		write_command(translateor([
			rd,
			rs1,
			rs2,
			51,
			0,
			6,
		]))
	end
end

def translateor(operands)
	command = 0
	rd=operands[0]
	command = set_bits(command, rd, 11, 7)
	rs1=operands[1]
	command = set_bits(command, rs1, 19, 15)
	rs2=operands[2]
	command = set_bits(command, rs2, 24, 20)
	opcode=operands[3]
	command = set_bits(command, opcode, 6, 0)
	funct7=operands[4]
	command = set_bits(command, funct7, 31, 25)
	funct3=operands[5]
	command = set_bits(command, funct3, 14, 12)
	return command
end


# ==============================================
# ==============================================
# and functions block
# ==============================================
def and(rd, rs1, rs2)
	skip_if_collect do
		write_command(translateand([
			rd,
			rs1,
			rs2,
			51,
			0,
			7,
		]))
	end
end

def translateand(operands)
	command = 0
	rd=operands[0]
	command = set_bits(command, rd, 11, 7)
	rs1=operands[1]
	command = set_bits(command, rs1, 19, 15)
	rs2=operands[2]
	command = set_bits(command, rs2, 24, 20)
	opcode=operands[3]
	command = set_bits(command, opcode, 6, 0)
	funct7=operands[4]
	command = set_bits(command, funct7, 31, 25)
	funct3=operands[5]
	command = set_bits(command, funct3, 14, 12)
	return command
end


# ==============================================
# ==============================================
# sll functions block
# ==============================================
def sll(rd, rs1, rs2)
	skip_if_collect do
		write_command(translatesll([
			rd,
			rs1,
			rs2,
			51,
			0,
			1,
		]))
	end
end

def translatesll(operands)
	command = 0
	rd=operands[0]
	command = set_bits(command, rd, 11, 7)
	rs1=operands[1]
	command = set_bits(command, rs1, 19, 15)
	rs2=operands[2]
	command = set_bits(command, rs2, 24, 20)
	opcode=operands[3]
	command = set_bits(command, opcode, 6, 0)
	funct7=operands[4]
	command = set_bits(command, funct7, 31, 25)
	funct3=operands[5]
	command = set_bits(command, funct3, 14, 12)
	return command
end


# ==============================================
# ==============================================
# srl functions block
# ==============================================
def srl(rd, rs1, rs2)
	skip_if_collect do
		write_command(translatesrl([
			rd,
			rs1,
			rs2,
			51,
			0,
			5,
		]))
	end
end

def translatesrl(operands)
	command = 0
	rd=operands[0]
	command = set_bits(command, rd, 11, 7)
	rs1=operands[1]
	command = set_bits(command, rs1, 19, 15)
	rs2=operands[2]
	command = set_bits(command, rs2, 24, 20)
	opcode=operands[3]
	command = set_bits(command, opcode, 6, 0)
	funct7=operands[4]
	command = set_bits(command, funct7, 31, 25)
	funct3=operands[5]
	command = set_bits(command, funct3, 14, 12)
	return command
end


# ==============================================
# ==============================================
# slt functions block
# ==============================================
def slt(rd, rs1, rs2)
	skip_if_collect do
		write_command(translateslt([
			rd,
			rs1,
			rs2,
			51,
			0,
			2,
		]))
	end
end

def translateslt(operands)
	command = 0
	rd=operands[0]
	command = set_bits(command, rd, 11, 7)
	rs1=operands[1]
	command = set_bits(command, rs1, 19, 15)
	rs2=operands[2]
	command = set_bits(command, rs2, 24, 20)
	opcode=operands[3]
	command = set_bits(command, opcode, 6, 0)
	funct7=operands[4]
	command = set_bits(command, funct7, 31, 25)
	funct3=operands[5]
	command = set_bits(command, funct3, 14, 12)
	return command
end


# ==============================================
# ==============================================
# sltu functions block
# ==============================================
def sltu(rd, rs1, rs2)
	skip_if_collect do
		write_command(translatesltu([
			rd,
			rs1,
			rs2,
			51,
			0,
			3,
		]))
	end
end

def translatesltu(operands)
	command = 0
	rd=operands[0]
	command = set_bits(command, rd, 11, 7)
	rs1=operands[1]
	command = set_bits(command, rs1, 19, 15)
	rs2=operands[2]
	command = set_bits(command, rs2, 24, 20)
	opcode=operands[3]
	command = set_bits(command, opcode, 6, 0)
	funct7=operands[4]
	command = set_bits(command, funct7, 31, 25)
	funct3=operands[5]
	command = set_bits(command, funct3, 14, 12)
	return command
end


# ==============================================
# ==============================================
# addi functions block
# ==============================================
def addi(rd, rs1, imm)
	skip_if_collect do
		write_command(translateaddi([
			rd,
			rs1,
			19,
			imm,
			0,
		]))
	end
end

def translateaddi(operands)
	command = 0
	rd=operands[0]
	command = set_bits(command, rd, 11, 7)
	rs1=operands[1]
	command = set_bits(command, rs1, 19, 15)
	opcode=operands[2]
	command = set_bits(command, opcode, 6, 0)
	imm=operands[3]
	command = set_bits(command, imm, 31, 20)
	funct3=operands[4]
	command = set_bits(command, funct3, 14, 12)
	return command
end


# ==============================================
# ==============================================
# andi functions block
# ==============================================
def andi(rd, rs1, imm)
	skip_if_collect do
		write_command(translateandi([
			rd,
			rs1,
			19,
			imm,
			7,
		]))
	end
end

def translateandi(operands)
	command = 0
	rd=operands[0]
	command = set_bits(command, rd, 11, 7)
	rs1=operands[1]
	command = set_bits(command, rs1, 19, 15)
	opcode=operands[2]
	command = set_bits(command, opcode, 6, 0)
	imm=operands[3]
	command = set_bits(command, imm, 31, 20)
	funct3=operands[4]
	command = set_bits(command, funct3, 14, 12)
	return command
end


# ==============================================
# ==============================================
# xori functions block
# ==============================================
def xori(rd, rs1, imm)
	skip_if_collect do
		write_command(translatexori([
			rd,
			rs1,
			19,
			imm,
			4,
		]))
	end
end

def translatexori(operands)
	command = 0
	rd=operands[0]
	command = set_bits(command, rd, 11, 7)
	rs1=operands[1]
	command = set_bits(command, rs1, 19, 15)
	opcode=operands[2]
	command = set_bits(command, opcode, 6, 0)
	imm=operands[3]
	command = set_bits(command, imm, 31, 20)
	funct3=operands[4]
	command = set_bits(command, funct3, 14, 12)
	return command
end


# ==============================================
# ==============================================
# ori functions block
# ==============================================
def ori(rd, rs1, imm)
	skip_if_collect do
		write_command(translateori([
			rd,
			rs1,
			19,
			imm,
			6,
		]))
	end
end

def translateori(operands)
	command = 0
	rd=operands[0]
	command = set_bits(command, rd, 11, 7)
	rs1=operands[1]
	command = set_bits(command, rs1, 19, 15)
	opcode=operands[2]
	command = set_bits(command, opcode, 6, 0)
	imm=operands[3]
	command = set_bits(command, imm, 31, 20)
	funct3=operands[4]
	command = set_bits(command, funct3, 14, 12)
	return command
end


# ==============================================
# ==============================================
# slli functions block
# ==============================================
def slli(rd, rs1, imm)
	skip_if_collect do
		write_command(translateslli([
			rd,
			rs1,
			19,
			imm,
			1,
		]))
	end
end

def translateslli(operands)
	command = 0
	rd=operands[0]
	command = set_bits(command, rd, 11, 7)
	rs1=operands[1]
	command = set_bits(command, rs1, 19, 15)
	opcode=operands[2]
	command = set_bits(command, opcode, 6, 0)
	imm=operands[3]
	command = set_bits(command, imm, 31, 20)
	funct3=operands[4]
	command = set_bits(command, funct3, 14, 12)
	return command
end


# ==============================================
# ==============================================
# srli functions block
# ==============================================
def srli(rd, rs1, imm)
	skip_if_collect do
		write_command(translatesrli([
			rd,
			rs1,
			19,
			imm,
			5,
		]))
	end
end

def translatesrli(operands)
	command = 0
	rd=operands[0]
	command = set_bits(command, rd, 11, 7)
	rs1=operands[1]
	command = set_bits(command, rs1, 19, 15)
	opcode=operands[2]
	command = set_bits(command, opcode, 6, 0)
	imm=operands[3]
	command = set_bits(command, imm, 31, 20)
	funct3=operands[4]
	command = set_bits(command, funct3, 14, 12)
	return command
end


# ==============================================
# ==============================================
# slti functions block
# ==============================================
def slti(rd, rs1, imm)
	skip_if_collect do
		write_command(translateslti([
			rd,
			rs1,
			19,
			imm,
			2,
		]))
	end
end

def translateslti(operands)
	command = 0
	rd=operands[0]
	command = set_bits(command, rd, 11, 7)
	rs1=operands[1]
	command = set_bits(command, rs1, 19, 15)
	opcode=operands[2]
	command = set_bits(command, opcode, 6, 0)
	imm=operands[3]
	command = set_bits(command, imm, 31, 20)
	funct3=operands[4]
	command = set_bits(command, funct3, 14, 12)
	return command
end


# ==============================================
# ==============================================
# sltiu functions block
# ==============================================
def sltiu(rd, rs1, imm)
	skip_if_collect do
		write_command(translatesltiu([
			rd,
			rs1,
			19,
			imm,
			3,
		]))
	end
end

def translatesltiu(operands)
	command = 0
	rd=operands[0]
	command = set_bits(command, rd, 11, 7)
	rs1=operands[1]
	command = set_bits(command, rs1, 19, 15)
	opcode=operands[2]
	command = set_bits(command, opcode, 6, 0)
	imm=operands[3]
	command = set_bits(command, imm, 31, 20)
	funct3=operands[4]
	command = set_bits(command, funct3, 14, 12)
	return command
end


# ==============================================
end
