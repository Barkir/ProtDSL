require_relative "../encoder"
asm = MicroAsm.new
asm.prog do

    addi r0, r0, 0
    xori r0, r0, 0
    ori r12, r31, 55
    andi r30, r20, 48
    slli r24, r27, 49
    srli r28, r4, 52
    slti r1, r8, 4
    sltiu r9, r12, 5

    ld r7, r8, 50
    lh r31, r29, 5656
    lw r8, r9, 46
    lbu r11, r13, 454
    lhu r30, r13, 454

    ecall
    ebreak



end
