require_relative "../encoder"

asm = MicroAsm.new
asm.prog do
    ADD r15, r2, r15
end
