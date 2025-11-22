require_relative "encoder"

asm = MicroAsm.new
asm.prog do
    SUB r8, r8, r8
end
