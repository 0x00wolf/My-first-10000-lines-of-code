asm("nop");
asm("movw $1234, %eax");

asm("movl -0x4(%rbp), %eax\n"
    "cmp $0xdeadbeef,%eax\n"
    "je myLabel\n"
    "xor %eax, %eax\n"
    "myLabel: movw $0xFFFF, %cx\n"
    "and %ecx, %eax");
