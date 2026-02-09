### Decoder usecase example.

We have this mircoassmbler code example

```ruby
require_relative "../encoder"

asm = MicroAsm.new
asm.prog do
    ADD r9, r9, r10
    XOR r8, r8, r8
    XOR r8, r9, r12
    ADD r9, r9, r10
    SUB r8, r8, r8
    XOR r8, r9, r12
end

```

- running `ruby add_sub.rb`
- `result.bin` is generated which looks like this (6 4-byte commands)
![alt text](./md/bytecode.png)
- running `ricsv_decode result.bin` and getting this
```
ADD      rd=-1    rs1=9    rs2=10:         a484b3
XOR      rd=-1    rs1=8    rs2=8:          844433
XOR      rd=-1    rs1=9    rs2=12:         c4c433
ADD      rd=-1    rs1=9    rs2=10:         a484b3
SUB      rd=-1    rs1=8    rs2=8:          40840433
XOR      rd=-1    rs1=9    rs2=12:         c4c433
```

The dump shows us _command name_, _use of registers_ and _command in hex_
