require_relative "../encoder"

asm = MicroAsm.new
asm.prog do
    xori r2, r7, 0
end
