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
        ON_DEBUG(hexDump(buffer));

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

        ON_DEBUG(hexDump(commands));
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
