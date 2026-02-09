#pragma once

#include <elfio/elfio.hpp>
#include <vector>
#include <unordered_map>
#include <string>

uint32_t getField(uint32_t command, int32_t from, int32_t to, int32_t mask);
uint32_t getCommand(const std::vector<uint8_t> commands, size_t pc);
int get_commands(std::vector<uint32_t> *commands, const std::string& filename, size_t *fsz);
size_t getFileSize(std::ifstream& file);
void init(std::vector<uint32_t> commands, size_t fsize);
uint32_t flipMask(uint32_t bitmask, int numBits);

using commandHash = std::unordered_map<std::string, std::vector<uint32_t>>;

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

void elfdump(const char* data, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (i % 16 == 0) {
            if (i != 0) std::cout << std::endl;
            std::cout << std::hex << std::setw(8) << std::setfill('0') << i << ": ";
        }
        printf("%02x ", (unsigned char)data[i]);
    }
    std::cout << std::dec << std::endl;
}

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

int get_commands(commandHash *commands, const std::string& filename, size_t *fsz) {
    std::ifstream file(filename, std::ios::binary);
    ELFIO::elfio reader;

    if (!file) {
        std::cerr << "Error reading file: " << filename << "\n";
        return -1;
    }

    if (!reader.load(filename)) {
        std::cerr << "Can't process elf file -> " << filename << std::endl;
        return -1;
    }

    // getting .text section
    auto text_section = reader.sections[".text"];
    if (!text_section) {
        std::cout << ".text section not found" << std::endl;
        return -1;
    }

    // getting  .text section bytes
    const char* data = text_section->get_data();
    if (data == nullptr) {
        std::cout << "no data in .text section" << std::endl;
        return -1;
    }

    int text_section_idx = text_section->get_index();

    auto symtab_section = reader.sections[".symtab"];
    if (!symtab_section) {
        std::cout << ".symtab section not found" << std::endl;
        return -1;

    }

    // accessing sym_table
    ELFIO::symbol_section_accessor symbols(reader, symtab_section);



    for (ELFIO::Elf_Xword i = 0; i < symbols.get_symbols_num(); ++i) {
        std::string name;
        ELFIO::Elf64_Addr value;
        ELFIO::Elf_Xword size;
        unsigned char bind;
        unsigned char type;
        ELFIO::Elf_Half section_index;
        unsigned char other;

        // getting info about symbol
        symbols.get_symbol(i, name, value, size, bind, type, section_index, other);

        // checking if it's section is text_section
        if (section_index == text_section_idx) {
            ELFIO::Elf64_Addr section_addr = text_section->get_address();
            ELFIO::Elf64_Addr offset_in_section = value - section_addr;

            // double check for offset in section
            if (offset_in_section < text_section->get_size())

                // adding to commands hash_table
                (*commands)[name] = std::vector<uint32_t>(
                reinterpret_cast<const uint32_t*>(data + offset_in_section),
                reinterpret_cast<const uint32_t*>(data + offset_in_section + size)
                );
            }
    }
    return 0;
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

