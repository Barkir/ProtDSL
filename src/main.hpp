#pragma once

uint32_t getField(uint32_t command, int32_t from, int32_t to, int32_t mask);
uint32_t getCommand(const std::vector<uint8_t> commands, size_t pc);
int get_commands(std::vector<uint32_t> *commands, const std::string& filename, size_t *fsz);
size_t getFileSize(std::ifstream& file);
void init(std::vector<uint32_t> commands, size_t fsize);
uint32_t flipMask(uint32_t bitmask, int numBits);

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

uint32_t flipMask(uint32_t bitmask, int numBits)
{
    uint32_t flippedMask = 0;
    for(unsigned int bit = 0; bit < numBits; ++bit)
    {
        uint32_t currentBit = (bitmask & (1 << bit)) >> bit;
        flippedMask |= currentBit << ((numBits - 1) - bit);
    }
    return flippedMask;
}

int get_commands(std::vector<uint32_t> *commands, const std::string& filename, size_t *fsz) {
    std::ifstream file(filename, std::ios::binary);

    if (!file) {
        std::cerr << "Error reading file: " << filename << "\n";
        return -1;
    }

    size_t fSize = getFileSize(file);
    *fsz = fSize;
    if (fSize % COMMAND_SIZE || fSize == 0) {
        std::cerr << "WRONG FILE SIZE " << fSize << "\n";
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

uint32_t getCommand(const std::vector<uint8_t> commands, size_t pc) {
    uint32_t command = 0;
    memcpy(&command, &commands[pc], 4);
    return command;
}

size_t getFileSize(std::ifstream& file) {
    if (!file.is_open()) return 0;

    file.seekg(0, std::ios::end);
    size_t size = file.tellg();
    file.seekg(0, std::ios::beg);

    return size;
}
uint32_t getField(uint32_t command, int32_t from, int32_t to, int32_t mask) {
    return (command >> from) & mask;
}

