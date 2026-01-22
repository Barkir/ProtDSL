#include <vector>
#include <cstdint>
#include <string>
#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <bitset>

#include "main.hpp"
#include "decoders.hpp"
#include "executers.hpp"

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

void init(std::vector<uint32_t> commands, size_t fsize) {
    struct SPU spu(fsize);

    std::vector<uint8_t>  commands_1byte(commands.size() * sizeof(uint32_t));
    memcpy(commands_1byte.data(), commands.data(), commands_1byte.size());

    size_t cm_sz = commands_1byte.size();
    while (spu.pc < cm_sz) {

        auto command = getCommand(commands_1byte, spu.pc);
        // std::cout << "command = \n" << std::bitset<32>(command) << std::endl;
        bigSwitch(spu, command);
        spu.pc += PC_INC;
	}
}


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
