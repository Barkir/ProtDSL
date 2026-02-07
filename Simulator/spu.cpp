#include <cstdint>

#include "spu.hpp"


uint8_t SPU::memory_read_uint8(uint32_t addr) const {
    return memory[addr];
}

int8_t SPU::memory_read_int8(uint32_t addr) const {
    return static_cast<int8_t>(memory[addr]);
}

uint16_t SPU::memory_read_uint16(uint32_t addr) const {
    return static_cast<uint16_t>(memory[addr]) |
            (static_cast<uint16_t>(memory[addr + 1]) << 8);
    }

int16_t SPU::memory_read_int16(uint32_t addr) const {
    return static_cast<int16_t>(memory_read_uint16(addr));
}

uint32_t SPU::memory_read_uint32(uint32_t addr) const {
    return static_cast<uint32_t>(memory[addr]) |
            (static_cast<uint32_t>(memory[addr + 1]) << 8) |
            (static_cast<uint32_t>(memory[addr + 2]) << 16) |
            (static_cast<uint32_t>(memory[addr + 3]) << 24);
}

int32_t SPU::memory_read_int32(uint32_t addr) const {
    return static_cast<int32_t>(memory_read_uint32(addr));
}

void SPU::memory_write_uint8(uint32_t addr, uint8_t value) {
        memory[addr] = value;
}

void SPU::memory_write_int8(uint32_t addr, int8_t value) {
    memory[addr] = static_cast<uint8_t>(value);
}

void SPU::memory_write_uint16(uint32_t addr, uint16_t value) {
    memory[addr]     = value & 0xFF;
    memory[addr + 1] = (value >> 8) & 0xFF;
}

void SPU::memory_write_int16(uint32_t addr, int16_t value) {
    memory_write_uint16(addr, static_cast<uint16_t>(value));
}

void SPU::memory_write_uint32(uint32_t addr, uint32_t value) {
    memory[addr]     = value & 0xFF;
    memory[addr + 1] = (value >> 8) & 0xFF;
    memory[addr + 2] = (value >> 16) & 0xFF;
    memory[addr + 3] = (value >> 24) & 0xFF;
}

void SPU::memory_write_int32(uint32_t addr, int32_t value) {
    memory_write_uint32(addr, static_cast<uint32_t>(value));
}

