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
