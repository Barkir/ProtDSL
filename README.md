# ProtDSL

[![License](https://img.shields.io/github/license/Barkir/ProtDSL?color=blue)](LICENSE)
[![GitHub Repo Stars](https://img.shields.io/github/stars/Barkir/ProtDSL?style=social)](https://github.com/Barkir/ProtDSL)
[![GitHub Last Commit](https://img.shields.io/github/last-commit/Barkir/ProtDSL?color=green)](https://github.com/Barkir/ProtDSL/commits/main)

![Ruby Badge](https://img.shields.io/badge/Ruby-CC342D?logo=ruby&logoColor=fff&style=for-the-badge)![RISC-V Badge](https://img.shields.io/badge/RISC--V-283272?logo=riscv&logoColor=fff&style=for-the-badge)

> A domain-specific language (DSL) for describing CPU instructions and automatically generating encoders, decoders, and simulators with RISC-V RV32I

[(older readme version)](./docs/README.md)

## Encoder Generator
- SimInfra generates a `.yaml` file with command specification (information to generate encoder and decoder)

<details>
<summary>
add instruction specification example
</summary>

```ruby
#<struct SimInfra::InstructionInfo name=:ADD, fields=[#<struct SimInfra::Field name=:rd, from=11, to=7, value=:reg>, #<struct SimInfra::Field name=:rs1, from=19, to=15, value=:reg>, #<struct SimInfra::Field name=:rs2, from=24, to=20, value=:reg>, #<struct SimInfra::Field name=:opcode, from=6, to=0, value=51>, #<struct SimInfra::Field name=:funct7, from=31, to=25, value=0>, #<struct SimInfra::Field name=:funct3, from=14, to=12, value=0>], format=:R, code=#<SimInfra::Scope:0x00007f6070021bd8 @tree=[#<struct SimInfra::IrStmt name=:new_var, oprnds=[rd:i32 (72)], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs1:i32 (72)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs1, #<SimInfra::XReg:0x00007f6070022628 @name=:rs1>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[rs2:i32 (72)], attrs=nil>, #<struct SimInfra::IrStmt name=:getreg, oprnds=[:rs2, #<SimInfra::XReg:0x00007f6070022600 @name=:rs2>], attrs=nil>, #<struct SimInfra::IrStmt name=:new_var, oprnds=[_tmp0:i32 (72)], attrs=nil>, #<struct SimInfra::IrStmt name=:add, oprnds=[_tmp0:i32 (72), rs1:i32 (72), rs2:i32 (72)], attrs=nil>, #<struct SimInfra::IrStmt name=:let, oprnds=[rd:i32 (72), _tmp0:i32 (72)], attrs=nil>, #<struct SimInfra::IrStmt name=:setreg, oprnds=[#<SimInfra::XReg:0x00007f6070022678 @name=:rd>, :rd], attrs=nil>], @vars={rd: rd:i32 (72), rs1: rs1:i32 (72), rs2: rs2:i32 (72), _tmp0: _tmp0:i32 (72)}>, args=[#<SimInfra::XReg:0x00007f6070022678 @name=:rd>, #<SimInfra::XReg:0x00007f6070022628 @name=:rs1>, #<SimInfra::XReg:0x00007f6070022600 @name=:rs2>], asm="ADD rd, rs1, rs2">
```

</details>

#### Desribing the process of encoding

##### 1. Generating a header
```ruby
    def self.write_encoder_header(encoder)
        encoder.write(CLASS_MICROASM)
        encoder.write(INITIALIZE_CODE)
        encoder.write(PROG_CODE)
        encoder.write(SET_BITS_CODE)
        encoder.write(SAVE_BINARY_CODE)
        encoder.write(RUN_BINARY_CODE)
        encoder.write(WRITE_COMMAND_CODE)
        encoder.write(LABEL_CODE)
        encoder.write(SKIP_IF_COLLECT_CODE)
    end
```
In future it is going to be a standard library where all the _helper_ methods of encoder are defined, but now it is a header.


##### 2. Generating translation function
```ruby
def self.create_translate_func(encoder, instr)
        encoder.write("def translate#{instr.name.to_s}(#{OPERANDS_ARRAY})\n")
        encoder.write("\tcommand = 0\n")
        instr.fields.each_with_index do |elem, index|
            encoder.write("\t#{elem.name}=#{OPERANDS_ARRAY}[#{index}]\n")
            encoder.write("\tcommand = set_bits(command, #{elem.name}, #{elem.from}, #{elem.to})\n")
        end
        encoder.write(END_TERM)
    end
```

#### 3. Result
```ruby
def translateADD(operands)
	command = 0
	rd=operands[0]
	command = set_bits(command, rd, 11, 7)
	rs1=operands[1]
	command = set_bits(command, rs1, 19, 15)
	rs2=operands[2]
	command = set_bits(command, rs2, 24, 20)
	opcode=operands[3]
	command = set_bits(command, opcode, 6, 0)
	funct7=operands[4]
	command = set_bits(command, funct7, 31, 25)
	funct3=operands[5]
	command = set_bits(command, funct3, 14, 12)
end
```

As the result we generate functions for all instructions and a `byte-code` file generated at the end.


##### Translation examples
| ASM | Byte-code |
|-----|-----------|
| ADD r8, r8, r8    | `C0 0C 00 00`|

### Decoder Tree

The task is to write an effective decoder based on building a decoding tree. For now I finished generating a decoder tree based on the **fields** of the instructions such as: _opcode_, _funct7_, _funct3_.

![decoder_tree](./md/tree.png)

