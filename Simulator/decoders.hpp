#pragma once
void inline decodeadd(SPU& spu, uint32_t command) {
	std::cout << "add " << std::endl;
}
void inline decodesub(SPU& spu, uint32_t command) {
	std::cout << "sub " << std::endl;
}
void inline decodexor(SPU& spu, uint32_t command) {
	std::cout << "xor " << std::endl;
}
void inline decodeor(SPU& spu, uint32_t command) {
	std::cout << "or " << std::endl;
}
void inline decodeand(SPU& spu, uint32_t command) {
	std::cout << "and " << std::endl;
}
void inline decodesll(SPU& spu, uint32_t command) {
	std::cout << "sll " << std::endl;
}
void inline decodesrl(SPU& spu, uint32_t command) {
	std::cout << "srl " << std::endl;
}
void inline decodeslt(SPU& spu, uint32_t command) {
	std::cout << "slt " << std::endl;
}
void inline decodesltu(SPU& spu, uint32_t command) {
	std::cout << "sltu " << std::endl;
}
void inline decodeaddi(SPU& spu, uint32_t command) {
	std::cout << "addi " << std::endl;
}
void inline decodeandi(SPU& spu, uint32_t command) {
	std::cout << "andi " << std::endl;
}
void inline decodexori(SPU& spu, uint32_t command) {
	std::cout << "xori " << std::endl;
}
void inline decodeori(SPU& spu, uint32_t command) {
	std::cout << "ori " << std::endl;
}
void inline decodeslli(SPU& spu, uint32_t command) {
	std::cout << "slli " << std::endl;
}
void inline decodesrli(SPU& spu, uint32_t command) {
	std::cout << "srli " << std::endl;
}
void inline decodeslti(SPU& spu, uint32_t command) {
	std::cout << "slti " << std::endl;
}
void inline decodesltiu(SPU& spu, uint32_t command) {
	std::cout << "sltiu " << std::endl;
}
void inline decodelb(SPU& spu, uint32_t command) {
	std::cout << "lb " << std::endl;
}
void inline decodelh(SPU& spu, uint32_t command) {
	std::cout << "lh " << std::endl;
}
void inline decodelw(SPU& spu, uint32_t command) {
	std::cout << "lw " << std::endl;
}
void inline decodelbu(SPU& spu, uint32_t command) {
	std::cout << "lbu " << std::endl;
}
void inline decodelhu(SPU& spu, uint32_t command) {
	std::cout << "lhu " << std::endl;
}
void inline decodeecall(SPU& spu, uint32_t command) {
	std::cout << "ecall " << std::endl;
}
void inline decodeebreak(SPU& spu, uint32_t command) {
	std::cout << "ebreak " << std::endl;
}
void inline decodesb(SPU& spu, uint32_t command) {
	std::cout << "sb " << std::endl;
}
void inline decodesh(SPU& spu, uint32_t command) {
	std::cout << "sh " << std::endl;
}
void inline decodesw(SPU& spu, uint32_t command) {
	std::cout << "sw " << std::endl;
}
void inline bigSwitchDecode(SPU& spu, uint32_t command){
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
				decodelb(spu, command);
				break;
			}
			case 1:
			{
				decodeaddi(spu, command);
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
				break;
			}
			case 1:
			{
				decodexori(spu, command);
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
				break;
			}
			case 1:
			{
				decodeslti(spu, command);
				break;
			}
			default: break;
			}
			break;
		}
		case 3:
		{
			decodeori(spu, command);
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
				break;
			}
			case 1:
			{
				decodeslli(spu, command);
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
				break;
			}
			case 1:
			{
				decodesrli(spu, command);
				break;
			}
			default: break;
			}
			break;
		}
		case 6:
		{
			decodesltiu(spu, command);
			break;
		}
		case 7:
		{
			decodeandi(spu, command);
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
				break;
			}
			case 4:
			{
				decodeadd(spu, command);
				break;
			}
			case 5:
			{
				decodesub(spu, command);
				break;
			}
			case 12:
			{
				decodeecall(spu, command);
				break;
			}
			case 14:
			{
				decodeebreak(spu, command);
				break;
			}
			default: break;
			}
			break;
		}
		case 9:
		{
			decodexor(spu, command);
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
				break;
			}
			case 1:
			{
				decodeslt(spu, command);
				break;
			}
			default: break;
			}
			break;
		}
		case 11:
		{
			decodeor(spu, command);
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
				break;
			}
			case 1:
			{
				decodesll(spu, command);
				break;
			}
			default: break;
			}
			break;
		}
		case 13:
		{
			decodesrl(spu, command);
			break;
		}
		case 14:
		{
			decodesltu(spu, command);
			break;
		}
		case 15:
		{
			decodeand(spu, command);
			break;
		}
		default: break;
		}
}
