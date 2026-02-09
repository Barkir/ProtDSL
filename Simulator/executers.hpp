#pragma once
void inline executeadd(SPU& spu, uint32_t command) {
	uint32_t rd = 0; //	new_var
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t rs2 = 0; //	new_var
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];
	uint32_t _tmp0 = 0; //	new_var
	_tmp0 = rs1 + rs2; //			add
	rd = _tmp0; //	let
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executesub(SPU& spu, uint32_t command) {
	uint32_t rd = 0; //	new_var
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t rs2 = 0; //	new_var
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];
	uint32_t _tmp1 = 0; //	new_var
	_tmp1 = rs1 - rs2; //			sub
	rd = _tmp1; //	let
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executexor(SPU& spu, uint32_t command) {
	uint32_t rd = 0; //	new_var
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t rs2 = 0; //	new_var
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];
	uint32_t _tmp2 = 0; //	new_var
	_tmp2 = rs1 ^ rs2; //			xor
	rd = _tmp2; //	let
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executeor(SPU& spu, uint32_t command) {
	uint32_t rd = 0; //	new_var
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t rs2 = 0; //	new_var
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];
	uint32_t _tmp3 = 0; //	new_var
	_tmp3 = rs1 | rs2; //			or
	rd = _tmp3; //	let
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executeand(SPU& spu, uint32_t command) {
	uint32_t rd = 0; //	new_var
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t rs2 = 0; //	new_var
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];
	uint32_t _tmp4 = 0; //	new_var
	_tmp4 = rs1 & rs2; //			and
	rd = _tmp4; //	let
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executesll(SPU& spu, uint32_t command) {
	uint32_t rd = 0; //	new_var
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t rs2 = 0; //	new_var
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];
	uint32_t _tmp5 = 0; //	new_var
	_tmp5 = rs1 << rs2; //			sll
	rd = _tmp5; //	let
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executesrl(SPU& spu, uint32_t command) {
	uint32_t rd = 0; //	new_var
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t rs2 = 0; //	new_var
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];
	uint32_t _tmp6 = 0; //	new_var
	_tmp6 = rs1 >> rs2; //			srl
	rd = _tmp6; //	let
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executeslt(SPU& spu, uint32_t command) {
	uint32_t rd = 0; //	new_var
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t rs2 = 0; //	new_var
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];
	uint32_t _tmp7 = 0; //	new_var
	_tmp7 = (rs1 < rs2)?1:0; //			slt
	rd = _tmp7; //	let
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executesltu(SPU& spu, uint32_t command) {
	uint32_t rd = 0; //	new_var
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t rs2 = 0; //	new_var
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];
	uint32_t _tmp8 = 0; //	new_var
	_tmp8 = (rs1 < rs2)?1:0; //			sltu
	rd = _tmp8; //	let
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executeaddi(SPU& spu, uint32_t command) {
	uint32_t rd = 0; //	new_var
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t imm = 0; //	new_var
	imm = getField(command, 20, 31, 0b00000000000000000000111111111111); // get_imm
	uint32_t _tmp9 = 0; //	new_var
	_tmp9 = (rs1 + imm);     //			addi
	rd = _tmp9; //	let
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executeandi(SPU& spu, uint32_t command) {
	uint32_t rd = 0; //	new_var
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t imm = 0; //	new_var
	imm = getField(command, 20, 31, 0b00000000000000000000111111111111); // get_imm
	uint32_t _tmp10 = 0; //	new_var
	_tmp10 = rs1 & imm; //			andi
	rd = _tmp10; //	let
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executexori(SPU& spu, uint32_t command) {
	uint32_t rd = 0; //	new_var
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t imm = 0; //	new_var
	imm = getField(command, 20, 31, 0b00000000000000000000111111111111); // get_imm
	uint32_t _tmp11 = 0; //	new_var
	_tmp11 = rs1 ^ imm; //			xori
	rd = _tmp11; //	let
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executeori(SPU& spu, uint32_t command) {
	uint32_t rd = 0; //	new_var
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t imm = 0; //	new_var
	imm = getField(command, 20, 31, 0b00000000000000000000111111111111); // get_imm
	uint32_t _tmp12 = 0; //	new_var
	_tmp12 = rs1 | imm; //			ori
	rd = _tmp12; //	let
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executeslli(SPU& spu, uint32_t command) {
	uint32_t rd = 0; //	new_var
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t imm = 0; //	new_var
	imm = getField(command, 20, 31, 0b00000000000000000000111111111111); // get_imm
	uint32_t _tmp13 = 0; //	new_var
	_tmp13 = rs1 << imm; //			slli
	rd = _tmp13; //	let
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executesrli(SPU& spu, uint32_t command) {
	uint32_t rd = 0; //	new_var
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t imm = 0; //	new_var
	imm = getField(command, 20, 31, 0b00000000000000000000111111111111); // get_imm
	uint32_t _tmp14 = 0; //	new_var
	_tmp14 = rs1 >> imm; //			srli
	rd = _tmp14; //	let
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executeslti(SPU& spu, uint32_t command) {
	uint32_t rd = 0; //	new_var
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t imm = 0; //	new_var
	imm = getField(command, 20, 31, 0b00000000000000000000111111111111); // get_imm
	uint32_t _tmp15 = 0; //	new_var
	_tmp15 = ((int32_t)rs1 < (int32_t)imm) ? 1 : 0; //		slti
	rd = _tmp15; //	let
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executesltiu(SPU& spu, uint32_t command) {
	uint32_t rd = 0; //	new_var
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t imm = 0; //	new_var
	imm = getField(command, 20, 31, 0b00000000000000000000111111111111); // get_imm
	uint32_t _tmp16 = 0; //	new_var
	_tmp16 = (rs1 < imm) ? 1 : 0; //		sltiu
	rd = _tmp16; //	let
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executelb(SPU& spu, uint32_t command) {
	uint32_t rd = 0; //	new_var
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t imm = 0; //	new_var
	imm = getField(command, 20, 31, 0b00000000000000000000111111111111); // get_imm
	uint32_t _tmp17 = 0; //	new_var
	int32_t addr = rs1 + imm;

      	int8_t byte = spu.memory_read_int8(addr);

      	_tmp17 = (uint32_t)(int32_t)byte; // signed extension
	rd = _tmp17; //	let
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executelh(SPU& spu, uint32_t command) {
	uint32_t rd = 0; //	new_var
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t imm = 0; //	new_var
	imm = getField(command, 20, 31, 0b00000000000000000000111111111111); // get_imm
	uint32_t _tmp18 = 0; //	new_var
	int32_t addr = rs1 + imm;

      	int16_t half = spu.memory_read_int16(addr);

      	_tmp18 = (uint32_t)(int32_t)half; // signed extension
	rd = _tmp18; //	let
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executelw(SPU& spu, uint32_t command) {
	uint32_t rd = 0; //	new_var
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t imm = 0; //	new_var
	imm = getField(command, 20, 31, 0b00000000000000000000111111111111); // get_imm
	uint32_t _tmp19 = 0; //	new_var
	int32_t addr = rs1 + imm;

      	_tmp19 = spu.memory_read_uint32(addr);
	rd = _tmp19; //	let
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executelbu(SPU& spu, uint32_t command) {
	uint32_t rd = 0; //	new_var
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t imm = 0; //	new_var
	imm = getField(command, 20, 31, 0b00000000000000000000111111111111); // get_imm
	uint32_t _tmp20 = 0; //	new_var
	int32_t addr = rs1 + imm;

      	_tmp20 = spu.memory_read_uint8(addr); // unsigned extension
	rd = _tmp20; //	let
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executelhu(SPU& spu, uint32_t command) {
	uint32_t rd = 0; //	new_var
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t imm = 0; //	new_var
	imm = getField(command, 20, 31, 0b00000000000000000000111111111111); // get_imm
	uint32_t _tmp21 = 0; //	new_var
	int32_t addr = rs1 + imm;

      	_tmp21 = spu.memory_read_uint16(addr); // unsigned extension
	rd = _tmp21; //	let
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executeecall(SPU& spu, uint32_t command) {
	// handling system call
	uint32_t syscall_num = spu.regs[17]; // a7
	uint32_t arg1 = spu.regs[10]; // a0
	uint32_t arg2 = spu.regs[11]; // a1
	uint32_t arg3 = spu.regs[12]; // a2
	// something is happening
}
void inline executeebreak(SPU& spu, uint32_t command) {
	spu.breakpoint = true;
}
void inline executejalr(SPU& spu, uint32_t command) {
	uint32_t rd = 0; //	new_var
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t imm = 0; //	new_var
	imm = getField(command, 20, 31, 0b00000000000000000000111111111111); // get_imm
	uint32_t _tmp22 = 0; //	new_var
	uint32_t t = spu.pc + 4;

      	spu.pc = (rs1 + imm) & ~1; // lowest bit = 0

      	_tmp22 = t; // saving address
	rd = _tmp22; //	let
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executesb(SPU& spu, uint32_t command) {
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t rs2 = 0; //	new_var
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];
	uint32_t imm = 0; //	new_var
	imm = getField(command, 7, 11, 0b00000000000000000000000000011111); // get_imm
	uint32_t _tmp23 = 0; //	new_var
	int32_t addr = _tmp23 + imm;

      	spu.memory_write_uint8(addr, rs2);
	rs1 = _tmp23; //	let
}
void inline executesh(SPU& spu, uint32_t command) {
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t rs2 = 0; //	new_var
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];
	uint32_t imm = 0; //	new_var
	imm = getField(command, 7, 11, 0b00000000000000000000000000011111); // get_imm
	uint32_t _tmp24 = 0; //	new_var
	int32_t addr = _tmp24 + imm;

      	spu.memory_write_uint16(addr, rs2);
	rs1 = _tmp24; //	let
}
void inline executesw(SPU& spu, uint32_t command) {
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t rs2 = 0; //	new_var
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];
	uint32_t imm = 0; //	new_var
	imm = getField(command, 7, 11, 0b00000000000000000000000000011111); // get_imm
	uint32_t _tmp25 = 0; //	new_var
	int32_t addr = _tmp25 + imm;

      	spu.memory_write_uint32(addr, rs2);
	rs1 = _tmp25; //	let
}
void inline executebeq(SPU& spu, uint32_t command) {
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t rs2 = 0; //	new_var
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];
	uint32_t imm = 0; //	new_var
	imm = getField(command, 7, 11, 0b00000000000000000000000000011111); // get_imm
	uint32_t _tmp26 = 0; //	new_var
	if (_tmp26 == rs1) spu.pc = spu.pc + rs2; //	beq
}
void inline executebne(SPU& spu, uint32_t command) {
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t rs2 = 0; //	new_var
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];
	uint32_t imm = 0; //	new_var
	imm = getField(command, 7, 11, 0b00000000000000000000000000011111); // get_imm
	uint32_t _tmp27 = 0; //	new_var
	if (_tmp27 != rs1) spu.pc = spu.pc + rs2; //	bne
}
void inline executeblt(SPU& spu, uint32_t command) {
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t rs2 = 0; //	new_var
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];
	uint32_t imm = 0; //	new_var
	imm = getField(command, 7, 11, 0b00000000000000000000000000011111); // get_imm
	uint32_t _tmp28 = 0; //	new_var
	if ((int32_t)_tmp28 < (int32_t)rs1) spu.pc = spu.pc + rs2; //	blt
}
void inline executebge(SPU& spu, uint32_t command) {
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t rs2 = 0; //	new_var
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];
	uint32_t imm = 0; //	new_var
	imm = getField(command, 7, 11, 0b00000000000000000000000000011111); // get_imm
	uint32_t _tmp29 = 0; //	new_var
	if ((int32_t)_tmp29 >= (int32_t)rs1) spu.pc = spu.pc + rs2; //	bge
}
void inline executebltu(SPU& spu, uint32_t command) {
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t rs2 = 0; //	new_var
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];
	uint32_t imm = 0; //	new_var
	imm = getField(command, 7, 11, 0b00000000000000000000000000011111); // get_imm
	uint32_t _tmp30 = 0; //	new_var
	if (_tmp30 < rs1) spu.pc = spu.pc + rs2; //	bltu
}
void inline executebgeu(SPU& spu, uint32_t command) {
	uint32_t rs1 = 0; //	new_var
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];
	uint32_t rs2 = 0; //	new_var
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];
	uint32_t imm = 0; //	new_var
	imm = getField(command, 7, 11, 0b00000000000000000000000000011111); // get_imm
	uint32_t _tmp31 = 0; //	new_var
	if (_tmp31 >= rs1) spu.pc = spu.pc + rs2; //	bgeu
}
void inline executelui(SPU& spu, uint32_t command) {
	uint32_t rd = 0; //	new_var
	uint32_t imm = 0; //	new_var
	imm = getField(command, 12, 31, 0b00000000000011111111111111111111); // get_imm
	rd = imm; //	let
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executeauipc(SPU& spu, uint32_t command) {
	uint32_t rd = 0; //	new_var
	uint32_t imm = 0; //	new_var
	imm = getField(command, 12, 31, 0b00000000000011111111111111111111); // get_imm
	rd = imm; //	let
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executejal(SPU& spu, uint32_t command) {
	uint32_t rd = 0; //	new_var
	uint32_t imm = 0; //	new_var
	imm = getField(command, 12, 19, 0b00000000000000000000000011111111); // get_imm
	rd = imm; //	let
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline bigSwitchEncode(SPU& spu, uint32_t command){
		uint32_t bits_1_4512 = 0;
		uint32_t bitMask = 0;
		bitMask = (command & 0b00000000000000000000000000010000) >> 2;
		bits_1_4512 += bitMask;
		bitMask = (command & 0b00000000000000000000000000100000) >> 4;
		bits_1_4512 += bitMask;
		bitMask = (command & 0b00000000000000000001000000000000) >> 12;
		bits_1_4512 += bitMask;
		switch(bits_1_4512) {
		case 0:
		{
			uint32_t bits_2_1314 = 0;
			uint32_t bitMask = 0;
			bitMask = (command & 0b00000000000000000010000000000000) >> 12;
			bits_2_1314 += bitMask;
			bitMask = (command & 0b00000000000000000100000000000000) >> 14;
			bits_2_1314 += bitMask;
			switch(bits_2_1314) {
			case 0:
			{
				executelb(spu, command);
				break;
			}
			case 1:
			{
				executelbu(spu, command);
				break;
			}
			case 2:
			{
				executelw(spu, command);
				break;
			}
			default: break;
			}
			break;
		}
		case 1:
		{
			uint32_t bits_2_14 = 0;
			uint32_t bitMask = 0;
			bitMask = (command & 0b00000000000000000100000000000000) >> 14;
			bits_2_14 += bitMask;
			switch(bits_2_14) {
			case 0:
			{
				executelh(spu, command);
				break;
			}
			case 1:
			{
				executelhu(spu, command);
				break;
			}
			default: break;
			}
			break;
		}
		case 2:
		{
			uint32_t bits_2_2613 = 0;
			uint32_t bitMask = 0;
			bitMask = (command & 0b00000000000000000000000000000100) >> 0;
			bits_2_2613 += bitMask;
			bitMask = (command & 0b00000000000000000000000001000000) >> 5;
			bits_2_2613 += bitMask;
			bitMask = (command & 0b00000000000000000010000000000000) >> 13;
			bits_2_2613 += bitMask;
			switch(bits_2_2613) {
			case 0:
			{
				executesb(spu, command);
				break;
			}
			case 1:
			{
				executesw(spu, command);
				break;
			}
			case 2:
			{
				uint32_t bits_3_14 = 0;
				uint32_t bitMask = 0;
				bitMask = (command & 0b00000000000000000100000000000000) >> 14;
				bits_3_14 += bitMask;
				switch(bits_3_14) {
				case 0:
				{
					executebeq(spu, command);
					break;
				}
				case 1:
				{
					executeblt(spu, command);
					break;
				}
				default: break;
				}
				break;
			}
			case 3:
			{
				executebltu(spu, command);
				break;
			}
			case 6:
			{
				uint32_t bits_3_3 = 0;
				uint32_t bitMask = 0;
				bitMask = (command & 0b00000000000000000000000000001000) >> 3;
				bits_3_3 += bitMask;
				switch(bits_3_3) {
				case 0:
				{
					executejalr(spu, command);
					break;
				}
				case 1:
				{
					executejal(spu, command);
					break;
				}
				default: break;
				}
				break;
			}
			default: break;
			}
			break;
		}
		case 3:
		{
			uint32_t bits_2_14613 = 0;
			uint32_t bitMask = 0;
			bitMask = (command & 0b00000000000000000100000000000000) >> 12;
			bits_2_14613 += bitMask;
			bitMask = (command & 0b00000000000000000000000001000000) >> 5;
			bits_2_14613 += bitMask;
			bitMask = (command & 0b00000000000000000010000000000000) >> 13;
			bits_2_14613 += bitMask;
			switch(bits_2_14613) {
			case 0:
			{
				executesh(spu, command);
				break;
			}
			case 2:
			{
				executebne(spu, command);
				break;
			}
			case 6:
			{
				executebge(spu, command);
				break;
			}
			case 7:
			{
				executebgeu(spu, command);
				break;
			}
			default: break;
			}
			break;
		}
		case 4:
		{
			uint32_t bits_2_13142 = 0;
			uint32_t bitMask = 0;
			bitMask = (command & 0b00000000000000000010000000000000) >> 11;
			bits_2_13142 += bitMask;
			bitMask = (command & 0b00000000000000000100000000000000) >> 13;
			bits_2_13142 += bitMask;
			bitMask = (command & 0b00000000000000000000000000000100) >> 2;
			bits_2_13142 += bitMask;
			switch(bits_2_13142) {
			case 0:
			{
				executeaddi(spu, command);
				break;
			}
			case 1:
			{
				executeauipc(spu, command);
				break;
			}
			case 2:
			{
				executexori(spu, command);
				break;
			}
			case 4:
			{
				executeslti(spu, command);
				break;
			}
			case 6:
			{
				executeori(spu, command);
				break;
			}
			default: break;
			}
			break;
		}
		case 5:
		{
			uint32_t bits_2_1314 = 0;
			uint32_t bitMask = 0;
			bitMask = (command & 0b00000000000000000010000000000000) >> 12;
			bits_2_1314 += bitMask;
			bitMask = (command & 0b00000000000000000100000000000000) >> 14;
			bits_2_1314 += bitMask;
			switch(bits_2_1314) {
			case 0:
			{
				executeslli(spu, command);
				break;
			}
			case 1:
			{
				executesrli(spu, command);
				break;
			}
			case 2:
			{
				executesltiu(spu, command);
				break;
			}
			case 3:
			{
				executeandi(spu, command);
				break;
			}
			default: break;
			}
			break;
		}
		case 6:
		{
			uint32_t bits_2_61314 = 0;
			uint32_t bitMask = 0;
			bitMask = (command & 0b00000000000000000000000001000000) >> 4;
			bits_2_61314 += bitMask;
			bitMask = (command & 0b00000000000000000010000000000000) >> 12;
			bits_2_61314 += bitMask;
			bitMask = (command & 0b00000000000000000100000000000000) >> 14;
			bits_2_61314 += bitMask;
			switch(bits_2_61314) {
			case 0:
			{
				uint32_t bits_3_230 = 0;
				uint32_t bitMask = 0;
				bitMask = (command & 0b00000000000000000000000000000100) >> 1;
				bits_3_230 += bitMask;
				bitMask = (command & 0b01000000000000000000000000000000) >> 30;
				bits_3_230 += bitMask;
				switch(bits_3_230) {
				case 0:
				{
					executeadd(spu, command);
					break;
				}
				case 1:
				{
					executesub(spu, command);
					break;
				}
				case 2:
				{
					executelui(spu, command);
					break;
				}
				default: break;
				}
				break;
			}
			case 1:
			{
				executexor(spu, command);
				break;
			}
			case 2:
			{
				executeslt(spu, command);
				break;
			}
			case 3:
			{
				executeor(spu, command);
				break;
			}
			case 4:
			{
				uint32_t bits_3_20 = 0;
				uint32_t bitMask = 0;
				bitMask = (command & 0b00000000000100000000000000000000) >> 20;
				bits_3_20 += bitMask;
				switch(bits_3_20) {
				case 0:
				{
					executeecall(spu, command);
					break;
				}
				case 1:
				{
					executeebreak(spu, command);
					break;
				}
				default: break;
				}
				break;
			}
			default: break;
			}
			break;
		}
		case 7:
		{
			uint32_t bits_2_1314 = 0;
			uint32_t bitMask = 0;
			bitMask = (command & 0b00000000000000000010000000000000) >> 12;
			bits_2_1314 += bitMask;
			bitMask = (command & 0b00000000000000000100000000000000) >> 14;
			bits_2_1314 += bitMask;
			switch(bits_2_1314) {
			case 0:
			{
				executesll(spu, command);
				break;
			}
			case 1:
			{
				executesrl(spu, command);
				break;
			}
			case 2:
			{
				executesltu(spu, command);
				break;
			}
			case 3:
			{
				executeand(spu, command);
				break;
			}
			default: break;
			}
			break;
		}
		default: break;
		}
}
