SET_BITS_CODE = <<~CODE
    def set_bits(number, value, from, to)
        width = to - from + 1
        mask = ((1 << width) - 1) << from
        (number & ~mask) | ((value & ((1 << width) - 1)) << from)
    end
CODE

INITIALIZE_CODE = <<~CODE
    def initialize
        @labels = {}
        @pc = 0
        @commands = []
        @registers = {}

        (0..31).each do |i|
            reg_name = "r\#{i}".to_sym
            self.define_singleton_method(reg_name) do
                i
            end
        end
    end
CODE

PROG_CODE = <<~CODE
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
        run_binary
    end
CODE

SAVE_BINARY_CODE = <<~CODE
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
CODE

RUN_BINARY_CODE = <<~CODE
    def run_binary(binary_filename="result.bin")
        absolute_path = File.expand_path(binary_filename)
        print absolute_path
        system(TOY_SIM + "toy_interpreter " + absolute_path)
    end
CODE

END_TERM="end\n"
OPERANDS_ARRAY="operands"
CLASS_MICROASM="class MicroAsm\n"
