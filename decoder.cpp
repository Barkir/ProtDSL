uint32_t getField(uint32_t command, int32_t from, int32_t to, int32_t mask) {
    return (command >> from) & mask;
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
