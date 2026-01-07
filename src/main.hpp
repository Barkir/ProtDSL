#pragma once

uint32_t getField(uint32_t command, int32_t from, int32_t to, int32_t mask);
uint32_t getCommand(const std::vector<uint8_t> commands, size_t pc);
int get_commands(std::vector<uint32_t> *commands, const std::string& filename, size_t *fsz);
size_t getFileSize(std::ifstream& file);
void init(std::vector<uint32_t> commands, size_t fsize);

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

struct MemorySPU {

    std::vector<uint8_t> memory;

    public:
        MemorySPU(size_t cap) : memory(cap, 0) {} // initialize vector if size cap and value 0.


    public: // operators
    uint8_t& operator[](uint32_t index) {
        return memory[index];
    }
};
struct SPU {

    uint32_t pc;
    uint32_t regs[32];
    size_t cap;

    MemorySPU memory; // class for memory

    SPU(size_t capIn) : pc(0), regs{}, cap(capIn), memory(capIn) {} // constructor

};

