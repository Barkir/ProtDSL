INSTRUCTION_SIZE_IN_BITS = 32
STANDARD_BIT_BASIS_SIZE  = 4

YAML_PATH = "/home/kirill/Side-Projects/ProtDSL/IR.yaml"


R_TYPE = %i[add sub xor or and sll srl slt sltu]

I_TYPE_ALU = %i[addi andi xori ori slli srli slti sltiu]
I_TYPE_LOAD = %i[lb lh lw lbu lhu]
I_TYPE_E = %i[ecall ebreak]
I_TYPE_J = %i[jalr]

S_TYPE = %i[sb sh sw]
B_TYPE = %i[beq bne blt bge bltu bgeu]
J_TYPE = %i[jal]
U_TYPE = %i[lui auipc]

ALL_TYPES = [R_TYPE, I_TYPE_ALU, I_TYPE_LOAD, I_TYPE_E, I_TYPE_J, S_TYPE, B_TYPE, J_TYPE, U_TYPE]



REGULAR_HEADER_CODE = <<~CODE
    #include <vector>
    #include <cstdint>
    #include <string>
    #include <fstream>
    #include <iostream>
    #include <cstring>
    #include <iomanip>

    uint32_t getField(uint32_t command, int32_t from, int32_t to, int32_t mask);
    uint32_t getCommand(const std::vector<uint8_t> commands, size_t pc);
    int get_commands(std::vector<uint32_t> *commands, const std::string& filename, size_t *fsz);
    size_t getFileSize(std::ifstream& file);

    const size_t COMMAND_SIZE = 4;
    const size_t DEFAULT_MEMORY_SIZE = 1024;
    const size_t REG_SIZE = 32;
    const size_t IMM_SIZE = 16;
    const size_t BEQ_OFFSET_SIZE = 16;
    const size_t LDP_OFFSET_SIZE = 11;
    const size_t LD_OFFSET_SIZE  = 16;
    const size_t ST_OFFSET_SIZE  = 16;
    const size_t PC_INC = 4;

    enum toyErrors {
    TOY_SUCCESS,
    TOY_FILE_READ_ERROR,
    TOY_WRONG_FILE_SIZE,

    TOY_FAILED = -1
};

CODE


GET_FILE_SIZE_CODE = <<~CODE
size_t getFileSize(std::ifstream& file) {
    if (!file.is_open()) return 0;

    file.seekg(0, std::ios::end);
    size_t size = file.tellg();
    file.seekg(0, std::ios::beg);

    return size;
}
CODE

GET_FIELD_CODE = <<~CODE
    uint32_t getField(uint32_t command, int32_t from, int32_t to, int32_t mask) {
        return (command >> from) & mask;
    }
CODE

GET_COMMAND_CODE = <<~CODE
uint32_t getCommand(const std::vector<uint8_t> commands, size_t pc) {
    uint32_t command = 0;
    memcpy(&command, &commands[pc], 4);
    return command;
}
CODE

MEMORY_STRUCT_CODE = <<~CODE
struct MemorySPU {

    std::vector<int8_t> memory;

    public:
        MemorySPU(size_t cap) : memory(cap, 0) {} // initialize vector if size cap and value 0.


    public: // operators
    int8_t& operator[](int32_t index) {
        return memory[index];
    }


};
CODE

SPU_STRUCT_CODE = <<~CODE
struct SPU {

    int32_t pc;
    uint32_t regs[32];
    size_t cap;

    MemorySPU memory; // class for memory

    SPU(size_t capIn) : memory(capIn), cap(capIn), pc(0), regs({}) {} // constructor

};
CODE

GET_COMMANDS_CODE = <<~CODE
int get_commands(std::vector<uint32_t> *commands, const std::string& filename, size_t *fsz) {
    std::ifstream file(filename, std::ios::binary);

    if (!file) {
        std::cerr << "Error reading file: " << filename << "\\n";
        return -1;
    }

    size_t fSize = getFileSize(file);
    *fsz = fSize;
    if (fSize % COMMAND_SIZE || fSize == 0) {
        std::cerr << "WRONG FILE SIZE " << fSize << "\\n";
        file.close();
        return -1;
    }

    if (file.is_open()) {
        std::vector<char> buffer(fSize);
        file.read(buffer.data(), fSize);
        // ON_DEBUG(hexDump(buffer));

        *commands = std::vector<uint32_t>(
        reinterpret_cast<const uint32_t*>(buffer.data()),
        reinterpret_cast<const uint32_t*>(buffer.data()) + fSize / COMMAND_SIZE
        );

        return 0;
    }
    return -1;
}
CODE

MAIN_CODE = <<~CODE
int main(int argc, char* argv[]) {

    if (argc >= 2)
    {
        std::string filename = argv[1];
        std::vector<uint32_t> commands;
        size_t fsize = 0;
        if (get_commands(&commands, filename, &fsize)) {
            return TOY_FAILED;
        }

        // ON_DEBUG(hexDump(commands));
        init(commands, fsize);
    }
}
CODE

INIT_HEADER_CODE = <<~CODE
void init(std::vector<uint32_t> commands, size_t fsize) {
    struct SPU spu(fsize);

    std::vector<uint8_t>  commands_1byte(commands.size() * sizeof(uint32_t));
    memcpy(commands_1byte.data(), commands.data(), commands_1byte.size());

    size_t cm_sz = commands_1byte.size();
    while (spu.pc < cm_sz) {

        auto command = getCommand(commands_1byte, spu.pc);


CODE

OPCODE_FROM = 0
OPCODE_TO   = 6



# ERB
