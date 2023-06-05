    msg db  "hello, world!",0x0a
    key db  0
section .text
    global _start
_start:
    mov rax, 1
    mov rdi, 1
    mov rsi, msg
    mov rdx, 14
    syscall
    mov rax, 0
    mov rdi, 0
    mov rsi, key
    mov rdx, 1
    syscall
    mov rax, 60
    mov rdi, 0
    syscall
