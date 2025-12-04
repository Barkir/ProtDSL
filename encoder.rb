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
# ADD functions block
# ==============================================
def ADD(rd, rs1, rs2)
	skip_if_collect do
	write_command(translateADD([rd, rs1, rs2, 51, 0, 0]))
	end
end


def translateADD(operands)
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
# SUB functions block
# ==============================================
def SUB(rd, rs1, rs2)
	skip_if_collect do
	write_command(translateSUB([rd, rs1, rs2, 51, 32, 0]))
	end
end


def translateSUB(operands)
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
# XOR functions block
# ==============================================
def XOR(rd, rs1, rs2)
	skip_if_collect do
	write_command(translateXOR([rd, rs1, rs2, 51, 0, 4]))
	end
end


def translateXOR(operands)
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
# OR functions block
# ==============================================
def OR(rd, rs1, rs2)
	skip_if_collect do
	write_command(translateOR([rd, rs1, rs2, 51, 0, 6]))
	end
end


def translateOR(operands)
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
# AND functions block
# ==============================================
def AND(rd, rs1, rs2)
	skip_if_collect do
	write_command(translateAND([rd, rs1, rs2, 51, 0, 7]))
	end
end


def translateAND(operands)
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
# SLL functions block
# ==============================================
def SLL(rd, rs1, rs2)
	skip_if_collect do
	write_command(translateSLL([rd, rs1, rs2, 51, 0, 1]))
	end
end


def translateSLL(operands)
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
# SRL functions block
# ==============================================
def SRL(rd, rs1, rs2)
	skip_if_collect do
	write_command(translateSRL([rd, rs1, rs2, 51, 0, 5]))
	end
end


def translateSRL(operands)
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
end
