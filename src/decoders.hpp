#pragma once
void inline decodeADD(SPU& spu, uint32_t command) {
	std::cout <<
                    "ADD \t "
                    <<"rd="<<rd_name<< std::setw(8)<<"rs1="<<rs1_name<< std::setw(8)<<"rs2="<<rs2_name
                    <<":"
                    << std::right << std::hex <<
                    std::setw(15) << std::setfill(' ') << command << std::dec << std::endl;
}
void inline decodeSUB(SPU& spu, uint32_t command) {
	std::cout <<
                    "SUB \t "
                    <<"rd="<<rd_name<< std::setw(8)<<"rs1="<<rs1_name<< std::setw(8)<<"rs2="<<rs2_name
                    <<":"
                    << std::right << std::hex <<
                    std::setw(15) << std::setfill(' ') << command << std::dec << std::endl;
}
void inline decodeXOR(SPU& spu, uint32_t command) {
	std::cout <<
                    "XOR \t "
                    <<"rd="<<rd_name<< std::setw(8)<<"rs1="<<rs1_name<< std::setw(8)<<"rs2="<<rs2_name
                    <<":"
                    << std::right << std::hex <<
                    std::setw(15) << std::setfill(' ') << command << std::dec << std::endl;
}
void inline decodeOR(SPU& spu, uint32_t command) {
	std::cout <<
                    "OR \t "
                    <<"rd="<<rd_name<< std::setw(8)<<"rs1="<<rs1_name<< std::setw(8)<<"rs2="<<rs2_name
                    <<":"
                    << std::right << std::hex <<
                    std::setw(15) << std::setfill(' ') << command << std::dec << std::endl;
}
void inline decodeAND(SPU& spu, uint32_t command) {
	std::cout <<
                    "AND \t "
                    <<"rd="<<rd_name<< std::setw(8)<<"rs1="<<rs1_name<< std::setw(8)<<"rs2="<<rs2_name
                    <<":"
                    << std::right << std::hex <<
                    std::setw(15) << std::setfill(' ') << command << std::dec << std::endl;
}
void inline decodeSLL(SPU& spu, uint32_t command) {
	std::cout <<
                    "SLL \t "
                    <<"rd="<<rd_name<< std::setw(8)<<"rs1="<<rs1_name<< std::setw(8)<<"rs2="<<rs2_name
                    <<":"
                    << std::right << std::hex <<
                    std::setw(15) << std::setfill(' ') << command << std::dec << std::endl;
}
void inline decodeSRL(SPU& spu, uint32_t command) {
	std::cout <<
                    "SRL \t "
                    <<"rd="<<rd_name<< std::setw(8)<<"rs1="<<rs1_name<< std::setw(8)<<"rs2="<<rs2_name
                    <<":"
                    << std::right << std::hex <<
                    std::setw(15) << std::setfill(' ') << command << std::dec << std::endl;
}
