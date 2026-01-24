#pragma once
void inline executeadd(SPU& spu, uint32_t command) {
	uint32_t rd = 0;

        	 //uint32_t rd_name = -1;
	uint32_t rs1 = 0;

        	 //uint32_t rs1_name = -1;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];

        	//rs1_name = getField(command, 15, 19, 0b00000000000000000000000000011111);
	uint32_t rs2 = 0;

        	 //uint32_t rs2_name = -1;
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];

        	//rs2_name = getField(command, 20, 24, 0b00000000000000000000000000011111);
	uint32_t _tmp0 = 0;

        	 //uint32_t _tmp0_name = -1;
	_tmp0 = rs1 + rs2;
	rd = _tmp0;
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executesub(SPU& spu, uint32_t command) {
	uint32_t rd = 0;

        	 //uint32_t rd_name = -1;
	uint32_t rs1 = 0;

        	 //uint32_t rs1_name = -1;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];

        	//rs1_name = getField(command, 15, 19, 0b00000000000000000000000000011111);
	uint32_t rs2 = 0;

        	 //uint32_t rs2_name = -1;
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];

        	//rs2_name = getField(command, 20, 24, 0b00000000000000000000000000011111);
	uint32_t _tmp1 = 0;

        	 //uint32_t _tmp1_name = -1;
	_tmp1 = rs1 - rs2;
	rd = _tmp1;
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executexor(SPU& spu, uint32_t command) {
	uint32_t rd = 0;

        	 //uint32_t rd_name = -1;
	uint32_t rs1 = 0;

        	 //uint32_t rs1_name = -1;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];

        	//rs1_name = getField(command, 15, 19, 0b00000000000000000000000000011111);
	uint32_t rs2 = 0;

        	 //uint32_t rs2_name = -1;
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];

        	//rs2_name = getField(command, 20, 24, 0b00000000000000000000000000011111);
	uint32_t _tmp2 = 0;

        	 //uint32_t _tmp2_name = -1;
	_tmp2 = rs1 ^ rs2;
	rd = _tmp2;
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executeor(SPU& spu, uint32_t command) {
	uint32_t rd = 0;

        	 //uint32_t rd_name = -1;
	uint32_t rs1 = 0;

        	 //uint32_t rs1_name = -1;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];

        	//rs1_name = getField(command, 15, 19, 0b00000000000000000000000000011111);
	uint32_t rs2 = 0;

        	 //uint32_t rs2_name = -1;
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];

        	//rs2_name = getField(command, 20, 24, 0b00000000000000000000000000011111);
	uint32_t _tmp3 = 0;

        	 //uint32_t _tmp3_name = -1;
	_tmp3 = rs1 | rs2;
	rd = _tmp3;
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executeand(SPU& spu, uint32_t command) {
	uint32_t rd = 0;

        	 //uint32_t rd_name = -1;
	uint32_t rs1 = 0;

        	 //uint32_t rs1_name = -1;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];

        	//rs1_name = getField(command, 15, 19, 0b00000000000000000000000000011111);
	uint32_t rs2 = 0;

        	 //uint32_t rs2_name = -1;
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];

        	//rs2_name = getField(command, 20, 24, 0b00000000000000000000000000011111);
	uint32_t _tmp4 = 0;

        	 //uint32_t _tmp4_name = -1;
	_tmp4 = rs1 & rs2;
	rd = _tmp4;
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executesll(SPU& spu, uint32_t command) {
	uint32_t rd = 0;

        	 //uint32_t rd_name = -1;
	uint32_t rs1 = 0;

        	 //uint32_t rs1_name = -1;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];

        	//rs1_name = getField(command, 15, 19, 0b00000000000000000000000000011111);
	uint32_t rs2 = 0;

        	 //uint32_t rs2_name = -1;
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];

        	//rs2_name = getField(command, 20, 24, 0b00000000000000000000000000011111);
	uint32_t _tmp5 = 0;

        	 //uint32_t _tmp5_name = -1;
	_tmp5 = rs1 << rs2;
	rd = _tmp5;
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executesrl(SPU& spu, uint32_t command) {
	uint32_t rd = 0;

        	 //uint32_t rd_name = -1;
	uint32_t rs1 = 0;

        	 //uint32_t rs1_name = -1;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];

        	//rs1_name = getField(command, 15, 19, 0b00000000000000000000000000011111);
	uint32_t rs2 = 0;

        	 //uint32_t rs2_name = -1;
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];

        	//rs2_name = getField(command, 20, 24, 0b00000000000000000000000000011111);
	uint32_t _tmp6 = 0;

        	 //uint32_t _tmp6_name = -1;
	_tmp6 = rs1 >> rs2;
	rd = _tmp6;
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executeslt(SPU& spu, uint32_t command) {
	uint32_t rd = 0;

        	 //uint32_t rd_name = -1;
	uint32_t rs1 = 0;

        	 //uint32_t rs1_name = -1;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];

        	//rs1_name = getField(command, 15, 19, 0b00000000000000000000000000011111);
	uint32_t rs2 = 0;

        	 //uint32_t rs2_name = -1;
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];

        	//rs2_name = getField(command, 20, 24, 0b00000000000000000000000000011111);
	uint32_t _tmp7 = 0;

        	 //uint32_t _tmp7_name = -1;
	_tmp7 = (rs1 < rs2)?1:0
;	rd = _tmp7;
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executesltu(SPU& spu, uint32_t command) {
	uint32_t rd = 0;

        	 //uint32_t rd_name = -1;
	uint32_t rs1 = 0;

        	 //uint32_t rs1_name = -1;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];

        	//rs1_name = getField(command, 15, 19, 0b00000000000000000000000000011111);
	uint32_t rs2 = 0;

        	 //uint32_t rs2_name = -1;
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];

        	//rs2_name = getField(command, 20, 24, 0b00000000000000000000000000011111);
	uint32_t _tmp8 = 0;

        	 //uint32_t _tmp8_name = -1;
	_tmp8 = (rs1 < rs2)?1:0
;	rd = _tmp8;
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executeaddi(SPU& spu, uint32_t command) {
	uint32_t rd = 0;

        	 //uint32_t rd_name = -1;
	uint32_t rs1 = 0;

        	 //uint32_t rs1_name = -1;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];

        	//rs1_name = getField(command, 15, 19, 0b00000000000000000000000000011111);
	uint32_t imm = 0;

        	 //uint32_t imm_name = -1;
	uint32_t _tmp9 = 0;

        	 //uint32_t _tmp9_name = -1;
	rd = _tmp9;
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executeandi(SPU& spu, uint32_t command) {
	uint32_t rd = 0;

        	 //uint32_t rd_name = -1;
	uint32_t rs1 = 0;

        	 //uint32_t rs1_name = -1;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];

        	//rs1_name = getField(command, 15, 19, 0b00000000000000000000000000011111);
	uint32_t imm = 0;

        	 //uint32_t imm_name = -1;
	uint32_t _tmp10 = 0;

        	 //uint32_t _tmp10_name = -1;
	rd = _tmp10;
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executexori(SPU& spu, uint32_t command) {
	uint32_t rd = 0;

        	 //uint32_t rd_name = -1;
	uint32_t rs1 = 0;

        	 //uint32_t rs1_name = -1;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];

        	//rs1_name = getField(command, 15, 19, 0b00000000000000000000000000011111);
	uint32_t imm = 0;

        	 //uint32_t imm_name = -1;
	uint32_t _tmp11 = 0;

        	 //uint32_t _tmp11_name = -1;
	rd = _tmp11;
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executeori(SPU& spu, uint32_t command) {
	uint32_t rd = 0;

        	 //uint32_t rd_name = -1;
	uint32_t rs1 = 0;

        	 //uint32_t rs1_name = -1;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];

        	//rs1_name = getField(command, 15, 19, 0b00000000000000000000000000011111);
	uint32_t imm = 0;

        	 //uint32_t imm_name = -1;
	uint32_t _tmp12 = 0;

        	 //uint32_t _tmp12_name = -1;
	rd = _tmp12;
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executeslli(SPU& spu, uint32_t command) {
	uint32_t rd = 0;

        	 //uint32_t rd_name = -1;
	uint32_t rs1 = 0;

        	 //uint32_t rs1_name = -1;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];

        	//rs1_name = getField(command, 15, 19, 0b00000000000000000000000000011111);
	uint32_t imm = 0;

        	 //uint32_t imm_name = -1;
	uint32_t _tmp13 = 0;

        	 //uint32_t _tmp13_name = -1;
	rd = _tmp13;
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executesrli(SPU& spu, uint32_t command) {
	uint32_t rd = 0;

        	 //uint32_t rd_name = -1;
	uint32_t rs1 = 0;

        	 //uint32_t rs1_name = -1;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];

        	//rs1_name = getField(command, 15, 19, 0b00000000000000000000000000011111);
	uint32_t imm = 0;

        	 //uint32_t imm_name = -1;
	uint32_t _tmp14 = 0;

        	 //uint32_t _tmp14_name = -1;
	rd = _tmp14;
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executeslti(SPU& spu, uint32_t command) {
	uint32_t rd = 0;

        	 //uint32_t rd_name = -1;
	uint32_t rs1 = 0;

        	 //uint32_t rs1_name = -1;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];

        	//rs1_name = getField(command, 15, 19, 0b00000000000000000000000000011111);
	uint32_t imm = 0;

        	 //uint32_t imm_name = -1;
	uint32_t _tmp15 = 0;

        	 //uint32_t _tmp15_name = -1;
	rd = _tmp15;
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executesltiu(SPU& spu, uint32_t command) {
	uint32_t rd = 0;

        	 //uint32_t rd_name = -1;
	uint32_t rs1 = 0;

        	 //uint32_t rs1_name = -1;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];

        	//rs1_name = getField(command, 15, 19, 0b00000000000000000000000000011111);
	uint32_t imm = 0;

        	 //uint32_t imm_name = -1;
	uint32_t _tmp16 = 0;

        	 //uint32_t _tmp16_name = -1;
	rd = _tmp16;
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executeld(SPU& spu, uint32_t command) {
	uint32_t rd = 0;

        	 //uint32_t rd_name = -1;
	uint32_t rs1 = 0;

        	 //uint32_t rs1_name = -1;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];

        	//rs1_name = getField(command, 15, 19, 0b00000000000000000000000000011111);
	uint32_t imm = 0;

        	 //uint32_t imm_name = -1;
	uint32_t _tmp17 = 0;

        	 //uint32_t _tmp17_name = -1;
	rd = _tmp17;
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executelh(SPU& spu, uint32_t command) {
	uint32_t rd = 0;

        	 //uint32_t rd_name = -1;
	uint32_t rs1 = 0;

        	 //uint32_t rs1_name = -1;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];

        	//rs1_name = getField(command, 15, 19, 0b00000000000000000000000000011111);
	uint32_t imm = 0;

        	 //uint32_t imm_name = -1;
	uint32_t _tmp18 = 0;

        	 //uint32_t _tmp18_name = -1;
	rd = _tmp18;
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executelw(SPU& spu, uint32_t command) {
	uint32_t rd = 0;

        	 //uint32_t rd_name = -1;
	uint32_t rs1 = 0;

        	 //uint32_t rs1_name = -1;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];

        	//rs1_name = getField(command, 15, 19, 0b00000000000000000000000000011111);
	uint32_t imm = 0;

        	 //uint32_t imm_name = -1;
	uint32_t _tmp19 = 0;

        	 //uint32_t _tmp19_name = -1;
	rd = _tmp19;
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executelbu(SPU& spu, uint32_t command) {
	uint32_t rd = 0;

        	 //uint32_t rd_name = -1;
	uint32_t rs1 = 0;

        	 //uint32_t rs1_name = -1;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];

        	//rs1_name = getField(command, 15, 19, 0b00000000000000000000000000011111);
	uint32_t imm = 0;

        	 //uint32_t imm_name = -1;
	uint32_t _tmp20 = 0;

        	 //uint32_t _tmp20_name = -1;
	rd = _tmp20;
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executelhu(SPU& spu, uint32_t command) {
	uint32_t rd = 0;

        	 //uint32_t rd_name = -1;
	uint32_t rs1 = 0;

        	 //uint32_t rs1_name = -1;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];

        	//rs1_name = getField(command, 15, 19, 0b00000000000000000000000000011111);
	uint32_t imm = 0;

        	 //uint32_t imm_name = -1;
	uint32_t _tmp21 = 0;

        	 //uint32_t _tmp21_name = -1;
	rd = _tmp21;
	spu.regs[getField(command, 7, 11, 0b00000000000000000000000000011111)] = rd;
}
void inline executeecall(SPU& spu, uint32_t command) {
}
void inline executeebreak(SPU& spu, uint32_t command) {
}
void inline executesb(SPU& spu, uint32_t command) {
	uint32_t rs1 = 0;

        	 //uint32_t rs1_name = -1;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];

        	//rs1_name = getField(command, 15, 19, 0b00000000000000000000000000011111);
	uint32_t rs2 = 0;

        	 //uint32_t rs2_name = -1;
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];

        	//rs2_name = getField(command, 20, 24, 0b00000000000000000000000000011111);
	uint32_t imm = 0;

        	 //uint32_t imm_name = -1;
	uint32_t _tmp22 = 0;

        	 //uint32_t _tmp22_name = -1;
	rs1 = _tmp22;
}
void inline executesh(SPU& spu, uint32_t command) {
	uint32_t rs1 = 0;

        	 //uint32_t rs1_name = -1;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];

        	//rs1_name = getField(command, 15, 19, 0b00000000000000000000000000011111);
	uint32_t rs2 = 0;

        	 //uint32_t rs2_name = -1;
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];

        	//rs2_name = getField(command, 20, 24, 0b00000000000000000000000000011111);
	uint32_t imm = 0;

        	 //uint32_t imm_name = -1;
	uint32_t _tmp23 = 0;

        	 //uint32_t _tmp23_name = -1;
	rs1 = _tmp23;
}
void inline executesw(SPU& spu, uint32_t command) {
	uint32_t rs1 = 0;

        	 //uint32_t rs1_name = -1;
	rs1 = spu.regs[getField(command, 15, 19, 0b00000000000000000000000000011111)];

        	//rs1_name = getField(command, 15, 19, 0b00000000000000000000000000011111);
	uint32_t rs2 = 0;

        	 //uint32_t rs2_name = -1;
	rs2 = spu.regs[getField(command, 20, 24, 0b00000000000000000000000000011111)];

        	//rs2_name = getField(command, 20, 24, 0b00000000000000000000000000011111);
	uint32_t imm = 0;

        	 //uint32_t imm_name = -1;
	uint32_t _tmp24 = 0;

        	 //uint32_t _tmp24_name = -1;
	rs1 = _tmp24;
}
void inline bigSwitch(SPU& spu, uint32_t command){
		uint32_t bits_1_5121314 = 0;
		uint32_t bitMask = 0;
	bitMask = (command & 0b00000000000000000000000000100000) >> 2;
		bits_1_5121314 += bitMask;
	bitMask = (command & 0b00000000000000000001000000000000) >> 10;
		bits_1_5121314 += bitMask;
	bitMask = (command & 0b00000000000000000010000000000000) >> 12;
		bits_1_5121314 += bitMask;
	bitMask = (command & 0b00000000000000000100000000000000) >> 14;
		bits_1_5121314 += bitMask;
		switch(bits_1_5121314) {
		case 0:
		{
			uint32_t bits_2_4 = 0;
			uint32_t bitMask = 0;
		bitMask = (command & 0b00000000000000000000000000010000) >> 4;
			bits_2_4 += bitMask;
			switch(bits_2_4) {
			case 0:
			{
				decodeld(spu, command);
				executeld(spu, command);
				break;
			}
			case 1:
			{
				decodeaddi(spu, command);
				executeaddi(spu, command);
				break;
			}
			default: break;
			}
			break;
		}
		case 1:
		{
			uint32_t bits_2_4 = 0;
			uint32_t bitMask = 0;
		bitMask = (command & 0b00000000000000000000000000010000) >> 4;
			bits_2_4 += bitMask;
			switch(bits_2_4) {
			case 0:
			{
				decodelbu(spu, command);
				executelbu(spu, command);
				break;
			}
			case 1:
			{
				decodexori(spu, command);
				executexori(spu, command);
				break;
			}
			default: break;
			}
			break;
		}
		case 2:
		{
			uint32_t bits_2_4 = 0;
			uint32_t bitMask = 0;
		bitMask = (command & 0b00000000000000000000000000010000) >> 4;
			bits_2_4 += bitMask;
			switch(bits_2_4) {
			case 0:
			{
				decodelw(spu, command);
				executelw(spu, command);
				break;
			}
			case 1:
			{
				decodeslti(spu, command);
				executeslti(spu, command);
				break;
			}
			default: break;
			}
			break;
		}
		case 3:
		{
			decodeori(spu, command);
			executeori(spu, command);
			break;
		}
		case 4:
		{
			uint32_t bits_2_4 = 0;
			uint32_t bitMask = 0;
		bitMask = (command & 0b00000000000000000000000000010000) >> 4;
			bits_2_4 += bitMask;
			switch(bits_2_4) {
			case 0:
			{
				decodelh(spu, command);
				executelh(spu, command);
				break;
			}
			case 1:
			{
				decodeslli(spu, command);
				executeslli(spu, command);
				break;
			}
			default: break;
			}
			break;
		}
		case 5:
		{
			uint32_t bits_2_4 = 0;
			uint32_t bitMask = 0;
		bitMask = (command & 0b00000000000000000000000000010000) >> 4;
			bits_2_4 += bitMask;
			switch(bits_2_4) {
			case 0:
			{
				decodelhu(spu, command);
				executelhu(spu, command);
				break;
			}
			case 1:
			{
				decodesrli(spu, command);
				executesrli(spu, command);
				break;
			}
			default: break;
			}
			break;
		}
		case 6:
		{
			decodesltiu(spu, command);
			executesltiu(spu, command);
			break;
		}
		case 7:
		{
			decodeandi(spu, command);
			executeandi(spu, command);
			break;
		}
		case 8:
		{
			uint32_t bits_2_642030 = 0;
			uint32_t bitMask = 0;
		bitMask = (command & 0b00000000000000000000000001000000) >> 3;
			bits_2_642030 += bitMask;
		bitMask = (command & 0b00000000000000000000000000010000) >> 2;
			bits_2_642030 += bitMask;
		bitMask = (command & 0b00000000000100000000000000000000) >> 19;
			bits_2_642030 += bitMask;
		bitMask = (command & 0b01000000000000000000000000000000) >> 30;
			bits_2_642030 += bitMask;
			switch(bits_2_642030) {
			case 0:
			{
				decodesb(spu, command);
				executesb(spu, command);
				break;
			}
			case 4:
			{
				decodeadd(spu, command);
				executeadd(spu, command);
				break;
			}
			case 5:
			{
				decodesub(spu, command);
				executesub(spu, command);
				break;
			}
			case 12:
			{
				decodeecall(spu, command);
				executeecall(spu, command);
				break;
			}
			case 14:
			{
				decodeebreak(spu, command);
				executeebreak(spu, command);
				break;
			}
			default: break;
			}
			break;
		}
		case 9:
		{
			decodexor(spu, command);
			executexor(spu, command);
			break;
		}
		case 10:
		{
			uint32_t bits_2_4 = 0;
			uint32_t bitMask = 0;
		bitMask = (command & 0b00000000000000000000000000010000) >> 4;
			bits_2_4 += bitMask;
			switch(bits_2_4) {
			case 0:
			{
				decodesw(spu, command);
				executesw(spu, command);
				break;
			}
			case 1:
			{
				decodeslt(spu, command);
				executeslt(spu, command);
				break;
			}
			default: break;
			}
			break;
		}
		case 11:
		{
			decodeor(spu, command);
			executeor(spu, command);
			break;
		}
		case 12:
		{
			uint32_t bits_2_4 = 0;
			uint32_t bitMask = 0;
		bitMask = (command & 0b00000000000000000000000000010000) >> 4;
			bits_2_4 += bitMask;
			switch(bits_2_4) {
			case 0:
			{
				decodesh(spu, command);
				executesh(spu, command);
				break;
			}
			case 1:
			{
				decodesll(spu, command);
				executesll(spu, command);
				break;
			}
			default: break;
			}
			break;
		}
		case 13:
		{
			decodesrl(spu, command);
			executesrl(spu, command);
			break;
		}
		case 14:
		{
			decodesltu(spu, command);
			executesltu(spu, command);
			break;
		}
		case 15:
		{
			decodeand(spu, command);
			executeand(spu, command);
			break;
		}
		default: break;
		}
}
