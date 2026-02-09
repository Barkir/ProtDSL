#pragma once
void inline decodeadd(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": add " << std::endl;
}
void inline decodesub(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": sub " << std::endl;
}
void inline decodexor(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": xor " << std::endl;
}
void inline decodeor(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": or " << std::endl;
}
void inline decodeand(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": and " << std::endl;
}
void inline decodesll(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": sll " << std::endl;
}
void inline decodesrl(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": srl " << std::endl;
}
void inline decodeslt(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": slt " << std::endl;
}
void inline decodesltu(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": sltu " << std::endl;
}
void inline decodeaddi(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": addi " << std::endl;
}
void inline decodeandi(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": andi " << std::endl;
}
void inline decodexori(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": xori " << std::endl;
}
void inline decodeori(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": ori " << std::endl;
}
void inline decodeslli(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": slli " << std::endl;
}
void inline decodesrli(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": srli " << std::endl;
}
void inline decodeslti(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": slti " << std::endl;
}
void inline decodesltiu(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": sltiu " << std::endl;
}
void inline decodelb(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": lb " << std::endl;
}
void inline decodelh(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": lh " << std::endl;
}
void inline decodelw(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": lw " << std::endl;
}
void inline decodelbu(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": lbu " << std::endl;
}
void inline decodelhu(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": lhu " << std::endl;
}
void inline decodeecall(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": ecall " << std::endl;
}
void inline decodeebreak(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": ebreak " << std::endl;
}
void inline decodejalr(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": jalr " << std::endl;
}
void inline decodesb(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": sb " << std::endl;
}
void inline decodesh(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": sh " << std::endl;
}
void inline decodesw(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": sw " << std::endl;
}
void inline decodebeq(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": beq " << std::endl;
}
void inline decodebne(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": bne " << std::endl;
}
void inline decodeblt(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": blt " << std::endl;
}
void inline decodebge(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": bge " << std::endl;
}
void inline decodebltu(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": bltu " << std::endl;
}
void inline decodebgeu(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": bgeu " << std::endl;
}
void inline decodelui(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": lui " << std::endl;
}
void inline decodeauipc(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": auipc " << std::endl;
}
void inline decodejal(SPU& spu, uint32_t command) {
	std::cout << std::hex << std::setw(8) << std::setfill('0') << spu.pc <<": jal " << std::endl;
}
void inline bigSwitchDecode(SPU& spu, uint32_t command){
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
				decodelb(spu, command);
				break;
			}
			case 1:
			{
				decodelbu(spu, command);
				break;
			}
			case 2:
			{
				decodelw(spu, command);
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
				decodelh(spu, command);
				break;
			}
			case 1:
			{
				decodelhu(spu, command);
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
				decodesb(spu, command);
				break;
			}
			case 1:
			{
				decodesw(spu, command);
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
					decodebeq(spu, command);
					break;
				}
				case 1:
				{
					decodeblt(spu, command);
					break;
				}
				default: break;
				}
				break;
			}
			case 3:
			{
				decodebltu(spu, command);
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
					decodejalr(spu, command);
					break;
				}
				case 1:
				{
					decodejal(spu, command);
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
				decodesh(spu, command);
				break;
			}
			case 2:
			{
				decodebne(spu, command);
				break;
			}
			case 6:
			{
				decodebge(spu, command);
				break;
			}
			case 7:
			{
				decodebgeu(spu, command);
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
				decodeaddi(spu, command);
				break;
			}
			case 1:
			{
				decodeauipc(spu, command);
				break;
			}
			case 2:
			{
				decodexori(spu, command);
				break;
			}
			case 4:
			{
				decodeslti(spu, command);
				break;
			}
			case 6:
			{
				decodeori(spu, command);
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
				decodeslli(spu, command);
				break;
			}
			case 1:
			{
				decodesrli(spu, command);
				break;
			}
			case 2:
			{
				decodesltiu(spu, command);
				break;
			}
			case 3:
			{
				decodeandi(spu, command);
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
					decodeadd(spu, command);
					break;
				}
				case 1:
				{
					decodesub(spu, command);
					break;
				}
				case 2:
				{
					decodelui(spu, command);
					break;
				}
				default: break;
				}
				break;
			}
			case 1:
			{
				decodexor(spu, command);
				break;
			}
			case 2:
			{
				decodeslt(spu, command);
				break;
			}
			case 3:
			{
				decodeor(spu, command);
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
					decodeecall(spu, command);
					break;
				}
				case 1:
				{
					decodeebreak(spu, command);
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
				decodesll(spu, command);
				break;
			}
			case 1:
			{
				decodesrl(spu, command);
				break;
			}
			case 2:
			{
				decodesltu(spu, command);
				break;
			}
			case 3:
			{
				decodeand(spu, command);
				break;
			}
			default: break;
			}
			break;
		}
		default: break;
		}
}
