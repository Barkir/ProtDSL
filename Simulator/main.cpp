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

void init(commandHash& commands, size_t fsize) {
    struct SPU spu(fsize);

    for (auto it = commands.begin(), end = commands.end(); it != end; ++it) {
        auto commandsData = it->second; // data of function
        auto commandsName = it->first;  // name of function

        if (commandsName == "main"){

        std::vector<uint8_t>  commands_1byte(commandsData.size() * sizeof(uint32_t));
        memcpy(commands_1byte.data(), commandsData.data(), commands_1byte.size());

        size_t cm_sz = commands_1byte.size();

        std::cout << "SIZE=" << cm_sz << std::endl;
        elfdump(reinterpret_cast<const char*>(&commands_1byte), cm_sz);
        std::cout << "<" << commandsName << ">" << std::endl;


        while (spu.pc < cm_sz) {
            auto command = getCommand(commands_1byte, spu.pc);
            bigSwitchDecode(spu, command);
            spu.pc += PC_INC;
	    }
        }
    }
}


int main(int argc, char* argv[]) {

    if (argc >= 2)
    {
        std::string filename = argv[1];
        commandHash commands;
        size_t fsize = 0;
        if (get_commands(&commands, filename, &fsize)) {
            return TOY_FAILED;
        }

        // ON_DEBUG(hexDump(commands));
        init(commands, fsize);
    }
}
