/*
mov $0xAABBCCDD, %eax
sahf
jz mylabel
and $0x31337, %eax
mylabel:
ret
*/

/*
example:

asm("movl -0x4(%rbp), %eax\n"
    "cmp $0xdeadbeef,%eax\n"
    "je myLabel\n"
    "xor %eax, %eax\n"
    "myLabel: movw $0xFFFF, %cx\n"
    "and %ecx, %eax");

asm(".byte 0x90"); is "nop"
asm(".byte 0x55"); is "push %rbp"
asm(".byte 0x48; .byte 0x89; .byte 0xE5"); 
    is "mov %rsp, %rbp"
*/

asm(".byte 0x90"); nop
asm(".byte 0x55"); push %rbp
asm(".byte 0x48, .byte 0x89; .byte 0xE5"); mov %rsp , %rbp
asm(".byte 0x89 /r AABBCCDD"); mov $0xAABBCCDD, %eax
asm(".byte 0x9E"); /sahf -- store AH into flags
asm(".byte 0x74;");
...snip
