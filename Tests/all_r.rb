require_relative "../encoder"

asm = MicroAsm.new
asm.prog do
    xor r2, r7, r8
    add r2, r1, r7
    send(:sub, r7, r8, r13)
    send(:or, r19, r18, r4)
    send(:and, r11, r2, r0)
    sll r17, r5, r0
    srl r18, r20, r21
    slt r19, r20, r16
    sltu r17, r20, r21
end
