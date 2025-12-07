uint32_t getField(uint32_t command, int32_t from, int32_t to, int32_t mask) {
    return (command >> from) & mask;
}
struct MemorySPU {

    std::vector<int8_t> memory;

    public:
        MemorySPU(size_t cap) : memory(cap, 0) {} // initialize vector if size cap and value 0.


    public: // operators
    int8_t& operator[](int32_t index) {
        return memory[index];
    }


};
struct SPU {

    int32_t pc;
    uint32_t regs[32];
    size_t cap;

    MemorySPU memory; // class for memory

    SPU(size_t capIn) : memory(capIn), cap(capIn), pc(0), regs({}) {} // constructor

};
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
        ON_DEBUG(hexDump(buffer));

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
void executeADD(SPU& spu, uint32_t command) {
	int32_t rd = 0;
	int32_t rs1 = 0;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	int32_t rs2 = 0;
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];
	int32_t _tmp0 = 0;
	_tmp0 = rs1 + rs2;
	rd = _tmp0;
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void executeSUB(SPU& spu, uint32_t command) {
	int32_t rd = 0;
	int32_t rs1 = 0;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	int32_t rs2 = 0;
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];
	int32_t _tmp1 = 0;
	_tmp1 = rs1 - rs2;
	rd = _tmp1;
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void executeXOR(SPU& spu, uint32_t command) {
	int32_t rd = 0;
	int32_t rs1 = 0;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	int32_t rs2 = 0;
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];
	int32_t _tmp2 = 0;
	rd = _tmp2;
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void executeOR(SPU& spu, uint32_t command) {
	int32_t rd = 0;
	int32_t rs1 = 0;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	int32_t rs2 = 0;
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];
	int32_t _tmp3 = 0;
	rd = _tmp3;
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void executeAND(SPU& spu, uint32_t command) {
	int32_t rd = 0;
	int32_t rs1 = 0;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	int32_t rs2 = 0;
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];
	int32_t _tmp4 = 0;
	rd = _tmp4;
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void executeSLL(SPU& spu, uint32_t command) {
	int32_t rd = 0;
	int32_t rs1 = 0;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	int32_t rs2 = 0;
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];
	int32_t _tmp5 = 0;
	rd = _tmp5;
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void executeSRL(SPU& spu, uint32_t command) {
	int32_t rd = 0;
	int32_t rs1 = 0;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	int32_t rs2 = 0;
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];
	int32_t _tmp6 = 0;
	rd = _tmp6;
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void init(std::vector<uint32_t> commands, size_t fsize) {
    struct SPU spu(fsize);

    std::vector<uint8_t>  commands_1byte(commands.size() * sizeof(uint32_t));
    memcpy(commands_1byte.data(), commands.data(), commands_1byte.size());

    size_t cm_sz = commands_1byte.size();
    while (spu.pc < cm_sz) {

        auto command = getCommand(commands_1byte, spu.pc);


		int field_level2 = getField(command, 0, 6)
		switch(field_level2) {
		case 51:
			int field_level3 = getField(command, 25, 31)
			switch(field_level3) {
			case 0:
				int field_level4 = getField(command, 12, 14)
				switch(field_level4) {
				case 0:
				executeADD(spu, command); break;
				case 4:
				executeXOR(spu, command); break;
				case 6:
				executeOR(spu, command); break;
				case 7:
				executeAND(spu, command); break;
				case 1:
				executeSLL(spu, command); break;
				case 5:
				executeSRL(spu, command); break;
				}
			case 32:
			executeSUB(spu, command); break;
			}
		}
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

        ON_DEBUG(hexDump(commands));
        init(commands, fsize);
    }
}
