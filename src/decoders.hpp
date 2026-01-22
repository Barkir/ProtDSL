#pragma once
void inline decodeADD(SPU& spu, uint32_t command) {
	std::cout << "ADD " << std::endl;
}
void inline decodeSUB(SPU& spu, uint32_t command) {
	std::cout << "SUB " << std::endl;
}
void inline decodeXOR(SPU& spu, uint32_t command) {
	std::cout << "XOR " << std::endl;
}
void inline decodeOR(SPU& spu, uint32_t command) {
	std::cout << "OR " << std::endl;
}
void inline decodeAND(SPU& spu, uint32_t command) {
	std::cout << "AND " << std::endl;
}
void inline decodeSLL(SPU& spu, uint32_t command) {
	std::cout << "SLL " << std::endl;
}
void inline decodeSRL(SPU& spu, uint32_t command) {
	std::cout << "SRL " << std::endl;
}
