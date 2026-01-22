#pragma once
void inline executeADD(SPU& spu, uint32_t command) {
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
void inline executeSUB(SPU& spu, uint32_t command) {
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
void inline executeXOR(SPU& spu, uint32_t command) {
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
void inline executeOR(SPU& spu, uint32_t command) {
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
void inline executeAND(SPU& spu, uint32_t command) {
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
void inline executeSLL(SPU& spu, uint32_t command) {
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
void inline executeSRL(SPU& spu, uint32_t command) {
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
void inline bigSwitch(SPU& spu, uint32_t command){
		int bits_1_1214 = 0;
		bits_1_1214 += (command & 00000000000000000000100000000000) >> 12;
		bits_1_1214 += (command & 00000000000000000010000000000000) >> 13;
		switch(bits_1_1214) {
		case 0:
		{
			int bits_2_26 = 0;
			bits_2_26 += (command & 00000010000000000000000000000000) >> 26;
			switch(bits_2_26) {
			case 0:
			{
				//decodeADD(spu, command);
				executeADD(spu, command);
				break;
			}
			case 1:
			{
				//decodeSUB(spu, command);
				executeSUB(spu, command);
				break;
			}
			default: break;
			}
			break;
		}
		case 1:
		{
			//decodeSLL(spu, command);
			executeSLL(spu, command);
			break;
		}
		case 2:
		{
			int bits_2_13 = 0;
			bits_2_13 += (command & 00000000000000000001000000000000) >> 13;
			switch(bits_2_13) {
			case 0:
			{
				//decodeXOR(spu, command);
				executeXOR(spu, command);
				break;
			}
			case 1:
			{
				//decodeOR(spu, command);
				executeOR(spu, command);
				break;
			}
			default: break;
			}
			break;
		}
		case 3:
		{
			int bits_2_13 = 0;
			bits_2_13 += (command & 00000000000000000001000000000000) >> 13;
			switch(bits_2_13) {
			case 0:
			{
				//decodeSRL(spu, command);
				executeSRL(spu, command);
				break;
			}
			case 1:
			{
				//decodeAND(spu, command);
				executeAND(spu, command);
				break;
			}
			default: break;
			}
			break;
		}
		default: break;
		}
}
