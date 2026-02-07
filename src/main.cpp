#include <vector>
#include <cstdint>
#include <string>
#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <bitset>

#include "main.hpp"
#include "spu.hpp"
#include "decoders.hpp"
#include "executers.hpp"

void init(std::vector<uint32_t> commands, size_t fsize) {
    struct SPU spu(fsize);

    std::vector<uint8_t>  commands_1byte(commands.size() * sizeof(uint32_t));
    memcpy(commands_1byte.data(), commands.data(), commands_1byte.size());

    size_t cm_sz = commands_1byte.size();
    while (spu.pc < cm_sz) {

        auto command = getCommand(commands_1byte, spu.pc);
        // std::cout << "command = \n" << std::bitset<32>(command) << std::endl;
        bigSwitchDecode(spu, command);
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
