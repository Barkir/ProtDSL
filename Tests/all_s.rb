require_relative "../encoder"

asm = MicroAsm.new
asm.prog do
    sb r15, r2, 500
    sh r12, r13, 600
    sw r11, r18, 700
end
