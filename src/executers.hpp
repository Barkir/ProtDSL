#pragma once
void inline execute#<OpenStruct name=:add, fields=[#<struct SimInfra::Field name=:rd, from=11, to=7, value=:reg>, #<struct SimInfra::Field name=:rs1, from=19, to=15, value=:reg>, #<struct SimInfra::Field name=:rs2, from=24, to=20, value=:reg>, #<struct SimInfra::Field name=:opcode, from=6, to=0, value=51>, #<struct SimInfra::Field name=:funct7, from=31, to=25, value=0>, #<struct SimInfra::Field name=:funct3, from=14, to=12, value=0>], format=:R, code=#<SimInfra::Scope:0x00007f2a1d593398 @tree=[#<struct SimInfra::IrStmt name=:new_var, oprnds=[rd:i32 (80)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs1:i32 (80)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs1, #<SimInfra::XReg:0x00007f2a1d592268 @name=:rs1>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs2:i32 (80)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs2, #<SimInfra::XReg:0x00007f2a1d5918e0 @name=:rs2>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[_tmp0:i32 (80)], attrs=nil>, #<struct SimInfra::IrStmt name=:add, oprnds=[_tmp0:i32 (80), rs1:i32 (80), rs2:i32 (80)], attrs=nil>, #<struct SimInfra::IrStmt name=:let, oprnds=[rd:i32 (80), _tmp0:i32 (80)], attrs=nil>, #<struct SimInfra::IrStmt name=:setreg, oprnds=[#<SimInfra::XReg:0x00007f2a1d590648 @name=:rd>, :rd], attrs=nil>], @vars={rd: rd:i32 (80), rs1: rs1:i32 (80), rs2: rs2:i32 (80), _tmp0: _tmp0:i32 (80)}>, args=[#<SimInfra::XReg:0x00007f2a1d590648 @name=:rd>, #<SimInfra::XReg:0x00007f2a1d592268 @name=:rs1>, #<SimInfra::XReg:0x00007f2a1d5918e0 @name=:rs2>], asm="add rd, rs1, rs2">(SPU& spu, uint32_t command) {
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
void inline execute#<OpenStruct name=:sub, fields=[#<struct SimInfra::Field name=:rd, from=11, to=7, value=:reg>, #<struct SimInfra::Field name=:rs1, from=19, to=15, value=:reg>, #<struct SimInfra::Field name=:rs2, from=24, to=20, value=:reg>, #<struct SimInfra::Field name=:opcode, from=6, to=0, value=51>, #<struct SimInfra::Field name=:funct7, from=31, to=25, value=32>, #<struct SimInfra::Field name=:funct3, from=14, to=12, value=0>], format=:R, code=#<SimInfra::Scope:0x00007f2a1d42aab0 @tree=[#<struct SimInfra::IrStmt name=:new_var, oprnds=[rd:i32 (120)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs1:i32 (120)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs1, #<SimInfra::XReg:0x00007f2a1d429d68 @name=:rs1>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs2:i32 (120)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs2, #<SimInfra::XReg:0x00007f2a1d429408 @name=:rs2>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[_tmp1:i32 (120)], attrs=nil>, #<struct SimInfra::IrStmt name=:sub, oprnds=[_tmp1:i32 (120), rs1:i32 (120), rs2:i32 (120)], attrs=nil>, #<struct SimInfra::IrStmt name=:let, oprnds=[rd:i32 (120), _tmp1:i32 (120)], attrs=nil>, #<struct SimInfra::IrStmt name=:setreg, oprnds=[#<SimInfra::XReg:0x00007f2a1d4283a0 @name=:rd>, :rd], attrs=nil>], @vars={rd: rd:i32 (120), rs1: rs1:i32 (120), rs2: rs2:i32 (120), _tmp1: _tmp1:i32 (120)}>, args=[#<SimInfra::XReg:0x00007f2a1d4283a0 @name=:rd>, #<SimInfra::XReg:0x00007f2a1d429d68 @name=:rs1>, #<SimInfra::XReg:0x00007f2a1d429408 @name=:rs2>], asm="sub rd, rs1, rs2">(SPU& spu, uint32_t command) {
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
void inline execute#<OpenStruct name=:xor, fields=[#<struct SimInfra::Field name=:rd, from=11, to=7, value=:reg>, #<struct SimInfra::Field name=:rs1, from=19, to=15, value=:reg>, #<struct SimInfra::Field name=:rs2, from=24, to=20, value=:reg>, #<struct SimInfra::Field name=:opcode, from=6, to=0, value=51>, #<struct SimInfra::Field name=:funct7, from=31, to=25, value=0>, #<struct SimInfra::Field name=:funct3, from=14, to=12, value=4>], format=:R, code=#<SimInfra::Scope:0x00007f2a1d426348 @tree=[#<struct SimInfra::IrStmt name=:new_var, oprnds=[rd:i32 (160)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs1:i32 (160)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs1, #<SimInfra::XReg:0x00007f2a1d425600 @name=:rs1>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs2:i32 (160)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs2, #<SimInfra::XReg:0x00007f2a1d424ca0 @name=:rs2>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[_tmp2:i32 (160)], attrs=nil>, #<struct SimInfra::IrStmt name=:xor, oprnds=[_tmp2:i32 (160), rs1:i32 (160), rs2:i32 (160)], attrs=nil>, #<struct SimInfra::IrStmt name=:let, oprnds=[rd:i32 (160), _tmp2:i32 (160)], attrs=nil>, #<struct SimInfra::IrStmt name=:setreg, oprnds=[#<SimInfra::XReg:0x00007f2a1d423c38 @name=:rd>, :rd], attrs=nil>], @vars={rd: rd:i32 (160), rs1: rs1:i32 (160), rs2: rs2:i32 (160), _tmp2: _tmp2:i32 (160)}>, args=[#<SimInfra::XReg:0x00007f2a1d423c38 @name=:rd>, #<SimInfra::XReg:0x00007f2a1d425600 @name=:rs1>, #<SimInfra::XReg:0x00007f2a1d424ca0 @name=:rs2>], asm="xor rd, rs1, rs2">(SPU& spu, uint32_t command) {
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
void inline execute#<OpenStruct name=:or, fields=[#<struct SimInfra::Field name=:rd, from=11, to=7, value=:reg>, #<struct SimInfra::Field name=:rs1, from=19, to=15, value=:reg>, #<struct SimInfra::Field name=:rs2, from=24, to=20, value=:reg>, #<struct SimInfra::Field name=:opcode, from=6, to=0, value=51>, #<struct SimInfra::Field name=:funct7, from=31, to=25, value=0>, #<struct SimInfra::Field name=:funct3, from=14, to=12, value=6>], format=:R, code=#<SimInfra::Scope:0x00007f2a1d421be0 @tree=[#<struct SimInfra::IrStmt name=:new_var, oprnds=[rd:i32 (200)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs1:i32 (200)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs1, #<SimInfra::XReg:0x00007f2a1d420e98 @name=:rs1>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs2:i32 (200)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs2, #<SimInfra::XReg:0x00007f2a1d420538 @name=:rs2>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[_tmp3:i32 (200)], attrs=nil>, #<struct SimInfra::IrStmt name=:or, oprnds=[_tmp3:i32 (200), rs1:i32 (200), rs2:i32 (200)], attrs=nil>, #<struct SimInfra::IrStmt name=:let, oprnds=[rd:i32 (200), _tmp3:i32 (200)], attrs=nil>, #<struct SimInfra::IrStmt name=:setreg, oprnds=[#<SimInfra::XReg:0x00007f2a1d50f4a8 @name=:rd>, :rd], attrs=nil>], @vars={rd: rd:i32 (200), rs1: rs1:i32 (200), rs2: rs2:i32 (200), _tmp3: _tmp3:i32 (200)}>, args=[#<SimInfra::XReg:0x00007f2a1d50f4a8 @name=:rd>, #<SimInfra::XReg:0x00007f2a1d420e98 @name=:rs1>, #<SimInfra::XReg:0x00007f2a1d420538 @name=:rs2>], asm="or rd, rs1, rs2">(SPU& spu, uint32_t command) {
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
void inline execute#<OpenStruct name=:and, fields=[#<struct SimInfra::Field name=:rd, from=11, to=7, value=:reg>, #<struct SimInfra::Field name=:rs1, from=19, to=15, value=:reg>, #<struct SimInfra::Field name=:rs2, from=24, to=20, value=:reg>, #<struct SimInfra::Field name=:opcode, from=6, to=0, value=51>, #<struct SimInfra::Field name=:funct7, from=31, to=25, value=0>, #<struct SimInfra::Field name=:funct3, from=14, to=12, value=7>], format=:R, code=#<SimInfra::Scope:0x00007f2a1d50d3b0 @tree=[#<struct SimInfra::IrStmt name=:new_var, oprnds=[rd:i32 (240)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs1:i32 (240)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs1, #<SimInfra::XReg:0x00007f2a1d50c668 @name=:rs1>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs2:i32 (240)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs2, #<SimInfra::XReg:0x00007f2a1d50bd08 @name=:rs2>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[_tmp4:i32 (240)], attrs=nil>, #<struct SimInfra::IrStmt name=:and, oprnds=[_tmp4:i32 (240), rs1:i32 (240), rs2:i32 (240)], attrs=nil>, #<struct SimInfra::IrStmt name=:let, oprnds=[rd:i32 (240), _tmp4:i32 (240)], attrs=nil>, #<struct SimInfra::IrStmt name=:setreg, oprnds=[#<SimInfra::XReg:0x00007f2a1d50aca0 @name=:rd>, :rd], attrs=nil>], @vars={rd: rd:i32 (240), rs1: rs1:i32 (240), rs2: rs2:i32 (240), _tmp4: _tmp4:i32 (240)}>, args=[#<SimInfra::XReg:0x00007f2a1d50aca0 @name=:rd>, #<SimInfra::XReg:0x00007f2a1d50c668 @name=:rs1>, #<SimInfra::XReg:0x00007f2a1d50bd08 @name=:rs2>], asm="and rd, rs1, rs2">(SPU& spu, uint32_t command) {
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
void inline execute#<OpenStruct name=:sll, fields=[#<struct SimInfra::Field name=:rd, from=11, to=7, value=:reg>, #<struct SimInfra::Field name=:rs1, from=19, to=15, value=:reg>, #<struct SimInfra::Field name=:rs2, from=24, to=20, value=:reg>, #<struct SimInfra::Field name=:opcode, from=6, to=0, value=51>, #<struct SimInfra::Field name=:funct7, from=31, to=25, value=0>, #<struct SimInfra::Field name=:funct3, from=14, to=12, value=1>], format=:R, code=#<SimInfra::Scope:0x00007f2a1d508ba8 @tree=[#<struct SimInfra::IrStmt name=:new_var, oprnds=[rd:i32 (280)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs1:i32 (280)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs1, #<SimInfra::XReg:0x00007f2a1d507e60 @name=:rs1>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs2:i32 (280)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs2, #<SimInfra::XReg:0x00007f2a1d507500 @name=:rs2>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[_tmp5:i32 (280)], attrs=nil>, #<struct SimInfra::IrStmt name=:sll, oprnds=[_tmp5:i32 (280), rs1:i32 (280), rs2:i32 (280)], attrs=nil>, #<struct SimInfra::IrStmt name=:let, oprnds=[rd:i32 (280), _tmp5:i32 (280)], attrs=nil>, #<struct SimInfra::IrStmt name=:setreg, oprnds=[#<SimInfra::XReg:0x00007f2a1d5063f8 @name=:rd>, :rd], attrs=nil>], @vars={rd: rd:i32 (280), rs1: rs1:i32 (280), rs2: rs2:i32 (280), _tmp5: _tmp5:i32 (280)}>, args=[#<SimInfra::XReg:0x00007f2a1d5063f8 @name=:rd>, #<SimInfra::XReg:0x00007f2a1d507e60 @name=:rs1>, #<SimInfra::XReg:0x00007f2a1d507500 @name=:rs2>], asm="sll rd, rs1, rs2">(SPU& spu, uint32_t command) {
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
void inline execute#<OpenStruct name=:srl, fields=[#<struct SimInfra::Field name=:rd, from=11, to=7, value=:reg>, #<struct SimInfra::Field name=:rs1, from=19, to=15, value=:reg>, #<struct SimInfra::Field name=:rs2, from=24, to=20, value=:reg>, #<struct SimInfra::Field name=:opcode, from=6, to=0, value=51>, #<struct SimInfra::Field name=:funct7, from=31, to=25, value=0>, #<struct SimInfra::Field name=:funct3, from=14, to=12, value=5>], format=:R, code=#<SimInfra::Scope:0x00007f2a1d5043a0 @tree=[#<struct SimInfra::IrStmt name=:new_var, oprnds=[rd:i32 (320)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs1:i32 (320)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs1, #<SimInfra::XReg:0x00007f2a1d503658 @name=:rs1>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs2:i32 (320)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs2, #<SimInfra::XReg:0x00007f2a1d502cf8 @name=:rs2>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[_tmp6:i32 (320)], attrs=nil>, #<struct SimInfra::IrStmt name=:srl, oprnds=[_tmp6:i32 (320), rs1:i32 (320), rs2:i32 (320)], attrs=nil>, #<struct SimInfra::IrStmt name=:let, oprnds=[rd:i32 (320), _tmp6:i32 (320)], attrs=nil>, #<struct SimInfra::IrStmt name=:setreg, oprnds=[#<SimInfra::XReg:0x00007f2a1d501bf0 @name=:rd>, :rd], attrs=nil>], @vars={rd: rd:i32 (320), rs1: rs1:i32 (320), rs2: rs2:i32 (320), _tmp6: _tmp6:i32 (320)}>, args=[#<SimInfra::XReg:0x00007f2a1d501bf0 @name=:rd>, #<SimInfra::XReg:0x00007f2a1d503658 @name=:rs1>, #<SimInfra::XReg:0x00007f2a1d502cf8 @name=:rs2>], asm="srl rd, rs1, rs2">(SPU& spu, uint32_t command) {
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
void inline execute#<OpenStruct name=:slt, fields=[#<struct SimInfra::Field name=:rd, from=11, to=7, value=:reg>, #<struct SimInfra::Field name=:rs1, from=19, to=15, value=:reg>, #<struct SimInfra::Field name=:rs2, from=24, to=20, value=:reg>, #<struct SimInfra::Field name=:opcode, from=6, to=0, value=51>, #<struct SimInfra::Field name=:funct7, from=31, to=25, value=0>, #<struct SimInfra::Field name=:funct3, from=14, to=12, value=2>], format=:R, code=#<SimInfra::Scope:0x00007f2a1d53fb80 @tree=[#<struct SimInfra::IrStmt name=:new_var, oprnds=[rd:i32 (360)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs1:i32 (360)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs1, #<SimInfra::XReg:0x00007f2a1d53ee38 @name=:rs1>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs2:i32 (360)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs2, #<SimInfra::XReg:0x00007f2a1d53e4d8 @name=:rs2>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[_tmp7:i32 (360)], attrs=nil>, #<struct SimInfra::IrStmt name=:slt, oprnds=[_tmp7:i32 (360), rs1:i32 (360), rs2:i32 (360)], attrs=nil>, #<struct SimInfra::IrStmt name=:let, oprnds=[rd:i32 (360), _tmp7:i32 (360)], attrs=nil>, #<struct SimInfra::IrStmt name=:setreg, oprnds=[#<SimInfra::XReg:0x00007f2a1d53d470 @name=:rd>, :rd], attrs=nil>], @vars={rd: rd:i32 (360), rs1: rs1:i32 (360), rs2: rs2:i32 (360), _tmp7: _tmp7:i32 (360)}>, args=[#<SimInfra::XReg:0x00007f2a1d53d470 @name=:rd>, #<SimInfra::XReg:0x00007f2a1d53ee38 @name=:rs1>, #<SimInfra::XReg:0x00007f2a1d53e4d8 @name=:rs2>], asm="slt rd, rs1, rs2">(SPU& spu, uint32_t command) {
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
void inline execute#<OpenStruct name=:sltu, fields=[#<struct SimInfra::Field name=:rd, from=11, to=7, value=:reg>, #<struct SimInfra::Field name=:rs1, from=19, to=15, value=:reg>, #<struct SimInfra::Field name=:rs2, from=24, to=20, value=:reg>, #<struct SimInfra::Field name=:opcode, from=6, to=0, value=51>, #<struct SimInfra::Field name=:funct7, from=31, to=25, value=0>, #<struct SimInfra::Field name=:funct3, from=14, to=12, value=3>], format=:R, code=#<SimInfra::Scope:0x00007f2a1d53b378 @tree=[#<struct SimInfra::IrStmt name=:new_var, oprnds=[rd:i32 (400)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs1:i32 (400)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs1, #<SimInfra::XReg:0x00007f2a1d53a630 @name=:rs1>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs2:i32 (400)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs2, #<SimInfra::XReg:0x00007f2a1d539cd0 @name=:rs2>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[_tmp8:i32 (400)], attrs=nil>, #<struct SimInfra::IrStmt name=:sltu, oprnds=[_tmp8:i32 (400), rs1:i32 (400), rs2:i32 (400)], attrs=nil>, #<struct SimInfra::IrStmt name=:let, oprnds=[rd:i32 (400), _tmp8:i32 (400)], attrs=nil>, #<struct SimInfra::IrStmt name=:setreg, oprnds=[#<SimInfra::XReg:0x00007f2a1d538bc8 @name=:rd>, :rd], attrs=nil>], @vars={rd: rd:i32 (400), rs1: rs1:i32 (400), rs2: rs2:i32 (400), _tmp8: _tmp8:i32 (400)}>, args=[#<SimInfra::XReg:0x00007f2a1d538bc8 @name=:rd>, #<SimInfra::XReg:0x00007f2a1d53a630 @name=:rs1>, #<SimInfra::XReg:0x00007f2a1d539cd0 @name=:rs2>], asm="sltu rd, rs1, rs2">(SPU& spu, uint32_t command) {
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
void inline execute#<OpenStruct name=:addi, fields=[#<struct SimInfra::Field name=:rd, from=11, to=7, value=:reg>, #<struct SimInfra::Field name=:rs1, from=19, to=15, value=:reg>, #<struct SimInfra::Field name=:opcode, from=6, to=0, value=19>, #<struct SimInfra::Field name=:imm, from=31, to=20, value=#<SimInfra::XImm:0x00007f2a1d537430 @name=:imm>>, #<struct SimInfra::Field name=:funct3, from=14, to=12, value=0>], format=:I, code=#<SimInfra::Scope:0x00007f2a1d536cb0 @tree=[#<struct SimInfra::IrStmt name=:new_var, oprnds=[rd:i32 (440)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs1:i32 (440)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs1, #<SimInfra::XReg:0x00007f2a1d535f68 @name=:rs1>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[imm:i32 (440)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[_tmp9:i32 (440)], attrs=nil>, #<struct SimInfra::IrStmt name=:addi, oprnds=[_tmp9:i32 (440), rs1:i32 (440), imm:i32 (440)], attrs=nil>, #<struct SimInfra::IrStmt name=:let, oprnds=[rd:i32 (440), _tmp9:i32 (440)], attrs=nil>, #<struct SimInfra::IrStmt name=:setreg, oprnds=[#<SimInfra::XReg:0x00007f2a1d534988 @name=:rd>, :rd], attrs=nil>], @vars={rd: rd:i32 (440), rs1: rs1:i32 (440), imm: imm:i32 (440), _tmp9: _tmp9:i32 (440)}>, args=[#<SimInfra::XReg:0x00007f2a1d534988 @name=:rd>, #<SimInfra::XReg:0x00007f2a1d535f68 @name=:rs1>, #<SimInfra::XImm:0x00007f2a1d537430 @name=:imm>], asm="addi rd, rs1, imm">(SPU& spu, uint32_t command) {
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
void inline execute#<OpenStruct name=:andi, fields=[#<struct SimInfra::Field name=:rd, from=11, to=7, value=:reg>, #<struct SimInfra::Field name=:rs1, from=19, to=15, value=:reg>, #<struct SimInfra::Field name=:opcode, from=6, to=0, value=19>, #<struct SimInfra::Field name=:imm, from=31, to=20, value=#<SimInfra::XImm:0x00007f2a1d533308 @name=:imm>>, #<struct SimInfra::Field name=:funct3, from=14, to=12, value=7>], format=:I, code=#<SimInfra::Scope:0x00007f2a1d532c78 @tree=[#<struct SimInfra::IrStmt name=:new_var, oprnds=[rd:i32 (472)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs1:i32 (472)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs1, #<SimInfra::XReg:0x00007f2a1d5313a0 @name=:rs1>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[imm:i32 (472)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[_tmp10:i32 (472)], attrs=nil>, #<struct SimInfra::IrStmt name=:andi, oprnds=[_tmp10:i32 (472), rs1:i32 (472), imm:i32 (472)], attrs=nil>, #<struct SimInfra::IrStmt name=:let, oprnds=[rd:i32 (472), _tmp10:i32 (472)], attrs=nil>, #<struct SimInfra::IrStmt name=:setreg, oprnds=[#<SimInfra::XReg:0x00007f2a1d5af3e0 @name=:rd>, :rd], attrs=nil>], @vars={rd: rd:i32 (472), rs1: rs1:i32 (472), imm: imm:i32 (472), _tmp10: _tmp10:i32 (472)}>, args=[#<SimInfra::XReg:0x00007f2a1d5af3e0 @name=:rd>, #<SimInfra::XReg:0x00007f2a1d5313a0 @name=:rs1>, #<SimInfra::XImm:0x00007f2a1d533308 @name=:imm>], asm="andi rd, rs1, imm">(SPU& spu, uint32_t command) {
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
void inline execute#<OpenStruct name=:xori, fields=[#<struct SimInfra::Field name=:rd, from=11, to=7, value=:reg>, #<struct SimInfra::Field name=:rs1, from=19, to=15, value=:reg>, #<struct SimInfra::Field name=:opcode, from=6, to=0, value=19>, #<struct SimInfra::Field name=:imm, from=31, to=20, value=#<SimInfra::XImm:0x00007f2a1d5add60 @name=:imm>>, #<struct SimInfra::Field name=:funct3, from=14, to=12, value=4>], format=:I, code=#<SimInfra::Scope:0x00007f2a1d5ad6d0 @tree=[#<struct SimInfra::IrStmt name=:new_var, oprnds=[rd:i32 (504)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs1:i32 (504)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs1, #<SimInfra::XReg:0x00007f2a1d5ac988 @name=:rs1>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[imm:i32 (504)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[_tmp11:i32 (504)], attrs=nil>, #<struct SimInfra::IrStmt name=:xori, oprnds=[_tmp11:i32 (504), rs1:i32 (504), imm:i32 (504)], attrs=nil>, #<struct SimInfra::IrStmt name=:let, oprnds=[rd:i32 (504), _tmp11:i32 (504)], attrs=nil>, #<struct SimInfra::IrStmt name=:setreg, oprnds=[#<SimInfra::XReg:0x00007f2a1d5ab3a8 @name=:rd>, :rd], attrs=nil>], @vars={rd: rd:i32 (504), rs1: rs1:i32 (504), imm: imm:i32 (504), _tmp11: _tmp11:i32 (504)}>, args=[#<SimInfra::XReg:0x00007f2a1d5ab3a8 @name=:rd>, #<SimInfra::XReg:0x00007f2a1d5ac988 @name=:rs1>, #<SimInfra::XImm:0x00007f2a1d5add60 @name=:imm>], asm="xori rd, rs1, imm">(SPU& spu, uint32_t command) {
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
void inline execute#<OpenStruct name=:ori, fields=[#<struct SimInfra::Field name=:rd, from=11, to=7, value=:reg>, #<struct SimInfra::Field name=:rs1, from=19, to=15, value=:reg>, #<struct SimInfra::Field name=:opcode, from=6, to=0, value=19>, #<struct SimInfra::Field name=:imm, from=31, to=20, value=#<SimInfra::XImm:0x00007f2a1d5a9d28 @name=:imm>>, #<struct SimInfra::Field name=:funct3, from=14, to=12, value=6>], format=:I, code=#<SimInfra::Scope:0x00007f2a1d5a9698 @tree=[#<struct SimInfra::IrStmt name=:new_var, oprnds=[rd:i32 (536)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs1:i32 (536)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs1, #<SimInfra::XReg:0x00007f2a1d5a88b0 @name=:rs1>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[imm:i32 (536)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[_tmp12:i32 (536)], attrs=nil>, #<struct SimInfra::IrStmt name=:ori, oprnds=[_tmp12:i32 (536), rs1:i32 (536), imm:i32 (536)], attrs=nil>, #<struct SimInfra::IrStmt name=:let, oprnds=[rd:i32 (536), _tmp12:i32 (536)], attrs=nil>, #<struct SimInfra::IrStmt name=:setreg, oprnds=[#<SimInfra::XReg:0x00007f2a1d5a72d0 @name=:rd>, :rd], attrs=nil>], @vars={rd: rd:i32 (536), rs1: rs1:i32 (536), imm: imm:i32 (536), _tmp12: _tmp12:i32 (536)}>, args=[#<SimInfra::XReg:0x00007f2a1d5a72d0 @name=:rd>, #<SimInfra::XReg:0x00007f2a1d5a88b0 @name=:rs1>, #<SimInfra::XImm:0x00007f2a1d5a9d28 @name=:imm>], asm="ori rd, rs1, imm">(SPU& spu, uint32_t command) {
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
void inline execute#<OpenStruct name=:slli, fields=[#<struct SimInfra::Field name=:rd, from=11, to=7, value=:reg>, #<struct SimInfra::Field name=:rs1, from=19, to=15, value=:reg>, #<struct SimInfra::Field name=:opcode, from=6, to=0, value=19>, #<struct SimInfra::Field name=:imm, from=31, to=20, value=#<SimInfra::XImm:0x00007f2a1d5a5c50 @name=:imm>>, #<struct SimInfra::Field name=:funct3, from=14, to=12, value=1>], format=:I, code=#<SimInfra::Scope:0x00007f2a1d5a55c0 @tree=[#<struct SimInfra::IrStmt name=:new_var, oprnds=[rd:i32 (568)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs1:i32 (568)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs1, #<SimInfra::XReg:0x00007f2a1d5a4648 @name=:rs1>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[imm:i32 (568)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[_tmp13:i32 (568)], attrs=nil>, #<struct SimInfra::IrStmt name=:slli, oprnds=[_tmp13:i32 (568), rs1:i32 (568), imm:i32 (568)], attrs=nil>, #<struct SimInfra::IrStmt name=:let, oprnds=[rd:i32 (568), _tmp13:i32 (568)], attrs=nil>, #<struct SimInfra::IrStmt name=:setreg, oprnds=[#<SimInfra::XReg:0x00007f2a1d5a2758 @name=:rd>, :rd], attrs=nil>], @vars={rd: rd:i32 (568), rs1: rs1:i32 (568), imm: imm:i32 (568), _tmp13: _tmp13:i32 (568)}>, args=[#<SimInfra::XReg:0x00007f2a1d5a2758 @name=:rd>, #<SimInfra::XReg:0x00007f2a1d5a4648 @name=:rs1>, #<SimInfra::XImm:0x00007f2a1d5a5c50 @name=:imm>], asm="slli rd, rs1, imm">(SPU& spu, uint32_t command) {
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
void inline execute#<OpenStruct name=:srli, fields=[#<struct SimInfra::Field name=:rd, from=11, to=7, value=:reg>, #<struct SimInfra::Field name=:rs1, from=19, to=15, value=:reg>, #<struct SimInfra::Field name=:opcode, from=6, to=0, value=19>, #<struct SimInfra::Field name=:imm, from=31, to=20, value=#<SimInfra::XImm:0x00007f2a1d5a0430 @name=:imm>>, #<struct SimInfra::Field name=:funct3, from=14, to=12, value=5>], format=:I, code=#<SimInfra::Scope:0x00007f2a1d5ff228 @tree=[#<struct SimInfra::IrStmt name=:new_var, oprnds=[rd:i32 (600)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs1:i32 (600)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs1, #<SimInfra::XReg:0x00007f2a1d5fc848 @name=:rs1>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[imm:i32 (600)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[_tmp14:i32 (600)], attrs=nil>, #<struct SimInfra::IrStmt name=:srli, oprnds=[_tmp14:i32 (600), rs1:i32 (600), imm:i32 (600)], attrs=nil>, #<struct SimInfra::IrStmt name=:let, oprnds=[rd:i32 (600), _tmp14:i32 (600)], attrs=nil>, #<struct SimInfra::IrStmt name=:setreg, oprnds=[#<SimInfra::XReg:0x00007f2a1d5f9b48 @name=:rd>, :rd], attrs=nil>], @vars={rd: rd:i32 (600), rs1: rs1:i32 (600), imm: imm:i32 (600), _tmp14: _tmp14:i32 (600)}>, args=[#<SimInfra::XReg:0x00007f2a1d5f9b48 @name=:rd>, #<SimInfra::XReg:0x00007f2a1d5fc848 @name=:rs1>, #<SimInfra::XImm:0x00007f2a1d5a0430 @name=:imm>], asm="srli rd, rs1, imm">(SPU& spu, uint32_t command) {
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
void inline execute#<OpenStruct name=:slti, fields=[#<struct SimInfra::Field name=:rd, from=11, to=7, value=:reg>, #<struct SimInfra::Field name=:rs1, from=19, to=15, value=:reg>, #<struct SimInfra::Field name=:opcode, from=6, to=0, value=19>, #<struct SimInfra::Field name=:imm, from=31, to=20, value=#<SimInfra::XImm:0x00007f2a1d5f69e8 @name=:imm>>, #<struct SimInfra::Field name=:funct3, from=14, to=12, value=2>], format=:I, code=#<SimInfra::Scope:0x00007f2a1d5f6358 @tree=[#<struct SimInfra::IrStmt name=:new_var, oprnds=[rd:i32 (632)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs1:i32 (632)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs1, #<SimInfra::XReg:0x00007f2a1d5f52a0 @name=:rs1>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[imm:i32 (632)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[_tmp15:i32 (632)], attrs=nil>, #<struct SimInfra::IrStmt name=:slti, oprnds=[_tmp15:i32 (632), rs1:i32 (632), imm:i32 (632)], attrs=nil>, #<struct SimInfra::IrStmt name=:let, oprnds=[rd:i32 (632), _tmp15:i32 (632)], attrs=nil>, #<struct SimInfra::IrStmt name=:setreg, oprnds=[#<SimInfra::XReg:0x00007f2a1d5f39a0 @name=:rd>, :rd], attrs=nil>], @vars={rd: rd:i32 (632), rs1: rs1:i32 (632), imm: imm:i32 (632), _tmp15: _tmp15:i32 (632)}>, args=[#<SimInfra::XReg:0x00007f2a1d5f39a0 @name=:rd>, #<SimInfra::XReg:0x00007f2a1d5f52a0 @name=:rs1>, #<SimInfra::XImm:0x00007f2a1d5f69e8 @name=:imm>], asm="slti rd, rs1, imm">(SPU& spu, uint32_t command) {
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
void inline execute#<OpenStruct name=:sltiu, fields=[#<struct SimInfra::Field name=:rd, from=11, to=7, value=:reg>, #<struct SimInfra::Field name=:rs1, from=19, to=15, value=:reg>, #<struct SimInfra::Field name=:opcode, from=6, to=0, value=19>, #<struct SimInfra::Field name=:imm, from=31, to=20, value=#<SimInfra::XImm:0x00007f2a1d5f2118 @name=:imm>>, #<struct SimInfra::Field name=:funct3, from=14, to=12, value=3>], format=:I, code=#<SimInfra::Scope:0x00007f2a1d5f1a88 @tree=[#<struct SimInfra::IrStmt name=:new_var, oprnds=[rd:i32 (664)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs1:i32 (664)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs1, #<SimInfra::XReg:0x00007f2a1d5f0d18 @name=:rs1>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[imm:i32 (664)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[_tmp16:i32 (664)], attrs=nil>, #<struct SimInfra::IrStmt name=:sltiu, oprnds=[_tmp16:i32 (664), rs1:i32 (664), imm:i32 (664)], attrs=nil>, #<struct SimInfra::IrStmt name=:let, oprnds=[rd:i32 (664), _tmp16:i32 (664)], attrs=nil>, #<struct SimInfra::IrStmt name=:setreg, oprnds=[#<SimInfra::XReg:0x00007f2a1d50f638 @name=:rd>, :rd], attrs=nil>], @vars={rd: rd:i32 (664), rs1: rs1:i32 (664), imm: imm:i32 (664), _tmp16: _tmp16:i32 (664)}>, args=[#<SimInfra::XReg:0x00007f2a1d50f638 @name=:rd>, #<SimInfra::XReg:0x00007f2a1d5f0d18 @name=:rs1>, #<SimInfra::XImm:0x00007f2a1d5f2118 @name=:imm>], asm="sltiu rd, rs1, imm">(SPU& spu, uint32_t command) {
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
void inline execute#<OpenStruct name=:ld, fields=[#<struct SimInfra::Field name=:rd, from=11, to=7, value=:reg>, #<struct SimInfra::Field name=:rs1, from=19, to=15, value=:reg>, #<struct SimInfra::Field name=:opcode, from=6, to=0, value=3>, #<struct SimInfra::Field name=:imm, from=31, to=20, value=#<SimInfra::XImm:0x00007f2a1d50de00 @name=:imm>>, #<struct SimInfra::Field name=:funct3, from=14, to=12, value=0>], format=:I, code=#<SimInfra::Scope:0x00007f2a1d50d748 @tree=[#<struct SimInfra::IrStmt name=:new_var, oprnds=[rd:i32 (696)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs1:i32 (696)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs1, #<SimInfra::XReg:0x00007f2a1d50c7f8 @name=:rs1>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[imm:i32 (696)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[_tmp17:i32 (696)], attrs=nil>, #<struct SimInfra::IrStmt name=:ld, oprnds=[_tmp17:i32 (696), rs1:i32 (696), imm:i32 (696)], attrs=nil>, #<struct SimInfra::IrStmt name=:let, oprnds=[rd:i32 (696), _tmp17:i32 (696)], attrs=nil>, #<struct SimInfra::IrStmt name=:setreg, oprnds=[#<SimInfra::XReg:0x00007f2a1d50af98 @name=:rd>, :rd], attrs=nil>], @vars={rd: rd:i32 (696), rs1: rs1:i32 (696), imm: imm:i32 (696), _tmp17: _tmp17:i32 (696)}>, args=[#<SimInfra::XReg:0x00007f2a1d50af98 @name=:rd>, #<SimInfra::XReg:0x00007f2a1d50c7f8 @name=:rs1>, #<SimInfra::XImm:0x00007f2a1d50de00 @name=:imm>], asm="ld rd, rs1, imm">(SPU& spu, uint32_t command) {
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
void inline execute#<OpenStruct name=:lh, fields=[#<struct SimInfra::Field name=:rd, from=11, to=7, value=:reg>, #<struct SimInfra::Field name=:rs1, from=19, to=15, value=:reg>, #<struct SimInfra::Field name=:opcode, from=6, to=0, value=3>, #<struct SimInfra::Field name=:imm, from=31, to=20, value=#<SimInfra::XImm:0x00007f2a1d509760 @name=:imm>>, #<struct SimInfra::Field name=:funct3, from=14, to=12, value=1>], format=:I, code=#<SimInfra::Scope:0x00007f2a1d5090d0 @tree=[#<struct SimInfra::IrStmt name=:new_var, oprnds=[rd:i32 (728)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs1:i32 (728)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs1, #<SimInfra::XReg:0x00007f2a1d5081d0 @name=:rs1>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[imm:i32 (728)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[_tmp18:i32 (728)], attrs=nil>, #<struct SimInfra::IrStmt name=:lh, oprnds=[_tmp18:i32 (728), rs1:i32 (728), imm:i32 (728)], attrs=nil>, #<struct SimInfra::IrStmt name=:let, oprnds=[rd:i32 (728), _tmp18:i32 (728)], attrs=nil>, #<struct SimInfra::IrStmt name=:setreg, oprnds=[#<SimInfra::XReg:0x00007f2a1d506970 @name=:rd>, :rd], attrs=nil>], @vars={rd: rd:i32 (728), rs1: rs1:i32 (728), imm: imm:i32 (728), _tmp18: _tmp18:i32 (728)}>, args=[#<SimInfra::XReg:0x00007f2a1d506970 @name=:rd>, #<SimInfra::XReg:0x00007f2a1d5081d0 @name=:rs1>, #<SimInfra::XImm:0x00007f2a1d509760 @name=:imm>], asm="lh rd, rs1, imm">(SPU& spu, uint32_t command) {
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
void inline execute#<OpenStruct name=:lw, fields=[#<struct SimInfra::Field name=:rd, from=11, to=7, value=:reg>, #<struct SimInfra::Field name=:rs1, from=19, to=15, value=:reg>, #<struct SimInfra::Field name=:opcode, from=6, to=0, value=3>, #<struct SimInfra::Field name=:imm, from=31, to=20, value=#<SimInfra::XImm:0x00007f2a1d505110 @name=:imm>>, #<struct SimInfra::Field name=:funct3, from=14, to=12, value=2>], format=:I, code=#<SimInfra::Scope:0x00007f2a1d504a80 @tree=[#<struct SimInfra::IrStmt name=:new_var, oprnds=[rd:i32 (760)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs1:i32 (760)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs1, #<SimInfra::XReg:0x00007f2a1d503bf8 @name=:rs1>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[imm:i32 (760)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[_tmp19:i32 (760)], attrs=nil>, #<struct SimInfra::IrStmt name=:lw, oprnds=[_tmp19:i32 (760), rs1:i32 (760), imm:i32 (760)], attrs=nil>, #<struct SimInfra::IrStmt name=:let, oprnds=[rd:i32 (760), _tmp19:i32 (760)], attrs=nil>, #<struct SimInfra::IrStmt name=:setreg, oprnds=[#<SimInfra::XReg:0x00007f2a1d5022d0 @name=:rd>, :rd], attrs=nil>], @vars={rd: rd:i32 (760), rs1: rs1:i32 (760), imm: imm:i32 (760), _tmp19: _tmp19:i32 (760)}>, args=[#<SimInfra::XReg:0x00007f2a1d5022d0 @name=:rd>, #<SimInfra::XReg:0x00007f2a1d503bf8 @name=:rs1>, #<SimInfra::XImm:0x00007f2a1d505110 @name=:imm>], asm="lw rd, rs1, imm">(SPU& spu, uint32_t command) {
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
void inline execute#<OpenStruct name=:lbu, fields=[#<struct SimInfra::Field name=:rd, from=11, to=7, value=:reg>, #<struct SimInfra::Field name=:rs1, from=19, to=15, value=:reg>, #<struct SimInfra::Field name=:opcode, from=6, to=0, value=3>, #<struct SimInfra::Field name=:imm, from=31, to=20, value=#<SimInfra::XImm:0x00007f2a1d500ac0 @name=:imm>>, #<struct SimInfra::Field name=:funct3, from=14, to=12, value=4>], format=:I, code=#<SimInfra::Scope:0x00007f2a1d500430 @tree=[#<struct SimInfra::IrStmt name=:new_var, oprnds=[rd:i32 (792)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs1:i32 (792)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs1, #<SimInfra::XReg:0x00007f2a1d53f590 @name=:rs1>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[imm:i32 (792)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[_tmp20:i32 (792)], attrs=nil>, #<struct SimInfra::IrStmt name=:lbu, oprnds=[_tmp20:i32 (792), rs1:i32 (792), imm:i32 (792)], attrs=nil>, #<struct SimInfra::IrStmt name=:let, oprnds=[rd:i32 (792), _tmp20:i32 (792)], attrs=nil>, #<struct SimInfra::IrStmt name=:setreg, oprnds=[#<SimInfra::XReg:0x00007f2a1d53dd08 @name=:rd>, :rd], attrs=nil>], @vars={rd: rd:i32 (792), rs1: rs1:i32 (792), imm: imm:i32 (792), _tmp20: _tmp20:i32 (792)}>, args=[#<SimInfra::XReg:0x00007f2a1d53dd08 @name=:rd>, #<SimInfra::XReg:0x00007f2a1d53f590 @name=:rs1>, #<SimInfra::XImm:0x00007f2a1d500ac0 @name=:imm>], asm="lbu rd, rs1, imm">(SPU& spu, uint32_t command) {
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
void inline execute#<OpenStruct name=:lhu, fields=[#<struct SimInfra::Field name=:rd, from=11, to=7, value=:reg>, #<struct SimInfra::Field name=:rs1, from=19, to=15, value=:reg>, #<struct SimInfra::Field name=:opcode, from=6, to=0, value=3>, #<struct SimInfra::Field name=:imm, from=31, to=20, value=#<SimInfra::XImm:0x00007f2a1d53c430 @name=:imm>>, #<struct SimInfra::Field name=:funct3, from=14, to=12, value=5>], format=:I, code=#<SimInfra::Scope:0x00007f2a1d53bda0 @tree=[#<struct SimInfra::IrStmt name=:new_var, oprnds=[rd:i32 (824)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs1:i32 (824)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs1, #<SimInfra::XReg:0x00007f2a1d53af40 @name=:rs1>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[imm:i32 (824)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[_tmp21:i32 (824)], attrs=nil>, #<struct SimInfra::IrStmt name=:lhu, oprnds=[_tmp21:i32 (824), rs1:i32 (824), imm:i32 (824)], attrs=nil>, #<struct SimInfra::IrStmt name=:let, oprnds=[rd:i32 (824), _tmp21:i32 (824)], attrs=nil>, #<struct SimInfra::IrStmt name=:setreg, oprnds=[#<SimInfra::XReg:0x00007f2a1d5396b8 @name=:rd>, :rd], attrs=nil>], @vars={rd: rd:i32 (824), rs1: rs1:i32 (824), imm: imm:i32 (824), _tmp21: _tmp21:i32 (824)}>, args=[#<SimInfra::XReg:0x00007f2a1d5396b8 @name=:rd>, #<SimInfra::XReg:0x00007f2a1d53af40 @name=:rs1>, #<SimInfra::XImm:0x00007f2a1d53c430 @name=:imm>], asm="lhu rd, rs1, imm">(SPU& spu, uint32_t command) {
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
void inline execute#<OpenStruct name=:ecall, fields=[#<struct SimInfra::Field name=:opcode, from=6, to=0, value=115>, #<struct SimInfra::Field name=:imm0, from=31, to=20, value=0>, #<struct SimInfra::Field name=:funct3, from=14, to=12, value=0>], format=:I, code=#<SimInfra::Scope:0x00007f2a1d5380d8 @tree=[], @vars={}>, args=[], asm="ecall">(SPU& spu, uint32_t command) {
}
void inline execute#<OpenStruct name=:ebreak, fields=[#<struct SimInfra::Field name=:opcode, from=6, to=0, value=115>, #<struct SimInfra::Field name=:imm0, from=31, to=20, value=1>, #<struct SimInfra::Field name=:funct3, from=14, to=12, value=0>], format=:I, code=#<SimInfra::Scope:0x00007f2a1d536e40 @tree=[], @vars={}>, args=[], asm="ebreak">(SPU& spu, uint32_t command) {
}
void inline execute#<OpenStruct name=:sb, fields=[#<struct SimInfra::Field name=:rs1, from=19, to=15, value=:reg>, #<struct SimInfra::Field name=:rs2, from=24, to=20, value=:reg>, #<struct SimInfra::Field name=:funct3, from=14, to=12, value=0>, #<struct SimInfra::Field name=:opcode, from=6, to=0, value=35>, #<struct SimInfra::Field name=:imm, from=11, to=7, value=0>, #<struct SimInfra::Field name=:imm1, from=31, to=25, value=0>], format=:S, code=#<SimInfra::Scope:0x00007f2a1d534780 @tree=[#<struct SimInfra::IrStmt name=:new_var, oprnds=[rs1:i32 (872)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs1, #<SimInfra::XReg:0x00007f2a1d533e98 @name=:rs1>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs2:i32 (872)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs2, #<SimInfra::XReg:0x00007f2a1d533538 @name=:rs2>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[imm:i32 (872)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[_tmp22:i32 (872)], attrs=nil>, #<struct SimInfra::IrStmt name=:sb, oprnds=[_tmp22:i32 (872), rs2:i32 (872), imm:i32 (872)], attrs=nil>, #<struct SimInfra::IrStmt name=:let, oprnds=[rs1:i32 (872), _tmp22:i32 (872)], attrs=nil>], @vars={rs1: rs1:i32 (872), rs2: rs2:i32 (872), imm: imm:i32 (872), _tmp22: _tmp22:i32 (872)}>, args=[#<SimInfra::XReg:0x00007f2a1d533e98 @name=:rs1>, #<SimInfra::XReg:0x00007f2a1d533538 @name=:rs2>, #<SimInfra::XImm:0x00007f2a1d531580 @name=:imm>], asm="sb rs1, rs2, imm">(SPU& spu, uint32_t command) {
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
void inline execute#<OpenStruct name=:sh, fields=[#<struct SimInfra::Field name=:rs1, from=19, to=15, value=:reg>, #<struct SimInfra::Field name=:rs2, from=24, to=20, value=:reg>, #<struct SimInfra::Field name=:funct3, from=14, to=12, value=1>, #<struct SimInfra::Field name=:opcode, from=6, to=0, value=35>, #<struct SimInfra::Field name=:imm, from=11, to=7, value=0>, #<struct SimInfra::Field name=:imm1, from=31, to=25, value=0>], format=:S, code=#<SimInfra::Scope:0x00007f2a1d5944f0 @tree=[#<struct SimInfra::IrStmt name=:new_var, oprnds=[rs1:i32 (904)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs1, #<SimInfra::XReg:0x00007f2a1d593c30 @name=:rs1>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs2:i32 (904)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs2, #<SimInfra::XReg:0x00007f2a1d593050 @name=:rs2>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[imm:i32 (904)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[_tmp23:i32 (904)], attrs=nil>, #<struct SimInfra::IrStmt name=:sh, oprnds=[_tmp23:i32 (904), rs2:i32 (904), imm:i32 (904)], attrs=nil>, #<struct SimInfra::IrStmt name=:let, oprnds=[rs1:i32 (904), _tmp23:i32 (904)], attrs=nil>], @vars={rs1: rs1:i32 (904), rs2: rs2:i32 (904), imm: imm:i32 (904), _tmp23: _tmp23:i32 (904)}>, args=[#<SimInfra::XReg:0x00007f2a1d593c30 @name=:rs1>, #<SimInfra::XReg:0x00007f2a1d593050 @name=:rs2>, #<SimInfra::XImm:0x00007f2a1d591778 @name=:imm>], asm="sh rs1, rs2, imm">(SPU& spu, uint32_t command) {
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
void inline execute#<OpenStruct name=:sw, fields=[#<struct SimInfra::Field name=:rs1, from=19, to=15, value=:reg>, #<struct SimInfra::Field name=:rs2, from=24, to=20, value=:reg>, #<struct SimInfra::Field name=:funct3, from=14, to=12, value=2>, #<struct SimInfra::Field name=:opcode, from=6, to=0, value=35>, #<struct SimInfra::Field name=:imm, from=11, to=7, value=0>, #<struct SimInfra::Field name=:imm1, from=31, to=25, value=0>], format=:S, code=#<SimInfra::Scope:0x00007f2a1d42bbe0 @tree=[#<struct SimInfra::IrStmt name=:new_var, oprnds=[rs1:i32 (936)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs1, #<SimInfra::XReg:0x00007f2a1d42b370 @name=:rs1>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs2:i32 (936)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs2, #<SimInfra::XReg:0x00007f2a1d42a998 @name=:rs2>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[imm:i32 (936)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[_tmp24:i32 (936)], attrs=nil>, #<struct SimInfra::IrStmt name=:sw, oprnds=[_tmp24:i32 (936), rs2:i32 (936), imm:i32 (936)], attrs=nil>, #<struct SimInfra::IrStmt name=:let, oprnds=[rs1:i32 (936), _tmp24:i32 (936)], attrs=nil>], @vars={rs1: rs1:i32 (936), rs2: rs2:i32 (936), imm: imm:i32 (936), _tmp24: _tmp24:i32 (936)}>, args=[#<SimInfra::XReg:0x00007f2a1d42b370 @name=:rs1>, #<SimInfra::XReg:0x00007f2a1d42a998 @name=:rs2>, #<SimInfra::XImm:0x00007f2a1d429278 @name=:imm>], asm="sw rs1, rs2, imm">(SPU& spu, uint32_t command) {
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
