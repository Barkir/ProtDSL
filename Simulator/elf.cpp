#include "ELFIO/elfio/elfio.hpp"
#include <iostream>
#include <iomanip>

void hexdump(const char* data, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (i % 16 == 0) {
            if (i != 0) std::cout << std::endl;
            std::cout << std::hex << std::setw(8) << std::setfill('0') << i << ": ";
        }
        printf("%02x ", (unsigned char)data[i]);
    }
    std::cout << std::dec << std::endl;
}

int main(void) {
    ELFIO::elfio reader;
    if (!reader.load("./a.out")) {
        std::cerr << "Can't find or process ELF file" << std::endl;
        return 1;
    }

    for (const auto& section : reader.sections) {
        auto name = section->get_name();

        if (section->get_size() == 0) continue;
        if (name == ".text" || name == ".data" || name == ".rodata") {
            const char* data = section->get_data();
            if (data != nullptr) {
                hexdump(data, std::min(section->get_size(), (ELFIO::Elf_Xword)64));
            }
        }
    }
}

