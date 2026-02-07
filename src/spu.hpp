#pragma once
#include <vector>

struct MemorySPU {
    std::vector<uint8_t> memory;

public:
    MemorySPU(size_t cap) : memory(cap, 0) {}

    uint8_t& operator[](uint32_t index) {
        return memory[index];
    }

    const uint8_t& operator[](uint32_t index) const {
        return memory[index];
    }
};

struct SPU {
    public: // arguments
    bool breakpoint;
    uint32_t pc;
    uint32_t regs[32];
    size_t cap;
    MemorySPU memory;

    public: // constructor
    SPU(size_t capIn) : pc(0), regs{}, cap(capIn), memory(capIn) {}

    public: // read memory
    uint8_t memory_read_uint8   (uint32_t addr)     const;
    int8_t memory_read_int8     (uint32_t addr)     const;
    uint16_t memory_read_uint16 (uint32_t addr)     const;
    int16_t memory_read_int16   (uint32_t addr)     const;
    uint32_t memory_read_uint32 (uint32_t addr)     const;
    int32_t memory_read_int32   (uint32_t addr)     const;


    public: // write memory
    void memory_write_uint8     (uint32_t addr, uint8_t value);
    void memory_write_int8      (uint32_t addr, int8_t  value);
    void memory_write_uint16    (uint32_t addr, uint16_t value);
    void memory_write_int16     (uint32_t addr, int16_t value);
    void memory_write_uint32    (uint32_t addr, uint32_t value);
    void memory_write_int32     (uint32_t addr, int32_t value);

};
