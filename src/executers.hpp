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
void inline bigSwitch(SPU& spu, uint32_t command){
		uint32_t bits_1_512 = 0;
		uint32_t bitMask = 0;
	bitMask = (command & 0b00000000000000000000000000100000) >> 5;
		bits_1_512 += bitMask;
	bitMask = (command & 0b00000000000000000001000000000000) >> 11;
		bits_1_512 += bitMask;
		bits_1_512 = flipMask(bits_1_512, 2);
		switch(bits_1_512) {
		case 0:
		{
			uint32_t bits_2_1314 = 0;
			uint32_t bitMask = 0;
		bitMask = (command & 0b00000000000000000010000000000000) >> 13;
			bits_2_1314 += bitMask;
		bitMask = (command & 0b00000000000000000100000000000000) >> 13;
			bits_2_1314 += bitMask;
			bits_2_1314 = flipMask(bits_2_1314, 2);
			switch(bits_2_1314) {
			case 0:
			{
				decodeaddi(spu, command);
				executeaddi(spu, command);
				break;
			}
			case 1:
			{
				decodexori(spu, command);
				executexori(spu, command);
				break;
			}
			case 2:
			{
				decodeslti(spu, command);
				executeslti(spu, command);
				break;
			}
			case 3:
			{
				decodeori(spu, command);
				executeori(spu, command);
				break;
			}
			default: break;
			}
			break;
		}
		case 1:
		{
			uint32_t bits_2_1314 = 0;
			uint32_t bitMask = 0;
		bitMask = (command & 0b00000000000000000010000000000000) >> 13;
			bits_2_1314 += bitMask;
		bitMask = (command & 0b00000000000000000100000000000000) >> 13;
			bits_2_1314 += bitMask;
			bits_2_1314 = flipMask(bits_2_1314, 2);
			switch(bits_2_1314) {
			case 0:
			{
				decodeslli(spu, command);
				executeslli(spu, command);
				break;
			}
			case 1:
			{
				decodesrli(spu, command);
				executesrli(spu, command);
				break;
			}
			case 2:
			{
				decodesltiu(spu, command);
				executesltiu(spu, command);
				break;
			}
			case 3:
			{
				decodeandi(spu, command);
				executeandi(spu, command);
				break;
			}
			default: break;
			}
			break;
		}
		case 2:
		{
			uint32_t bits_2_1314 = 0;
			uint32_t bitMask = 0;
		bitMask = (command & 0b00000000000000000010000000000000) >> 13;
			bits_2_1314 += bitMask;
		bitMask = (command & 0b00000000000000000100000000000000) >> 13;
			bits_2_1314 += bitMask;
			bits_2_1314 = flipMask(bits_2_1314, 2);
			switch(bits_2_1314) {
			case 0:
			{
				uint32_t bits_3_30 = 0;
				uint32_t bitMask = 0;
			bitMask = (command & 0b01000000000000000000000000000000) >> 30;
				bits_3_30 += bitMask;
				bits_3_30 = flipMask(bits_3_30, 2);
				switch(bits_3_30) {
				case 0:
				{
					decodeadd(spu, command);
					executeadd(spu, command);
					break;
				}
				case 1:
				{
					decodesub(spu, command);
					executesub(spu, command);
					break;
				}
				default: break;
				}
				break;
			}
			case 1:
			{
				decodexor(spu, command);
				executexor(spu, command);
				break;
			}
			case 2:
			{
				decodeslt(spu, command);
				executeslt(spu, command);
				break;
			}
			case 3:
			{
				decodeor(spu, command);
				executeor(spu, command);
				break;
			}
			default: break;
			}
			break;
		}
		case 3:
		{
			uint32_t bits_2_1314 = 0;
			uint32_t bitMask = 0;
		bitMask = (command & 0b00000000000000000010000000000000) >> 13;
			bits_2_1314 += bitMask;
		bitMask = (command & 0b00000000000000000100000000000000) >> 13;
			bits_2_1314 += bitMask;
			bits_2_1314 = flipMask(bits_2_1314, 2);
			switch(bits_2_1314) {
			case 0:
			{
				decodesll(spu, command);
				executesll(spu, command);
				break;
			}
			case 1:
			{
				decodesrl(spu, command);
				executesrl(spu, command);
				break;
			}
			case 2:
			{
				decodesltu(spu, command);
				executesltu(spu, command);
				break;
			}
			case 3:
			{
				decodeand(spu, command);
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
