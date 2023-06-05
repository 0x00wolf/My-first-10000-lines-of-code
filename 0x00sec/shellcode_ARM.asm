.text
.globl _start

_start: mov r7, #11
    mov r1, #0
    mov r2, #0
    ldr r0,=msg
    swi #0

.data
msg:
    .asciz "/system/bin/sh"
