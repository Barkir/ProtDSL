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
void inline decodeld(SPU& spu, uint32_t command) {
	std::cout << "ld " << std::endl;
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
