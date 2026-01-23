require_relative "../encoder"

asm = MicroAsm.new
asm.prog do
    ADD r1, r2, r7
    SLL r5, r6, r8
    XOR r2, r7, r9
    XOR r8, r9, r9

    ADD r1, r2, r7
    SLL r5, r6, r8
    XOR r8, r9, r9

    SUB r1, r2, r7
    SRL r5, r6, r8
    XOR r8, r9, r9

    ADD r1, r2, r7
    SLL r5, r6, r8
    XOR r8, r9, r9

    ADDI r1, r2, 500
    XORI r8, r10, 448
end
