section .text
        global _start

_start:
        mov rax, 0x3b       ; SYS_exec
        mov rdx, 0          ; No Env
        mov rsi, 0          ; No argv
        mov rdi, cmd        ; char *cmd
        syscall

cmd:    db '/bin/sh',0
