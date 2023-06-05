    global mfw_exit
    global mfw_write
    global mfw_close
    global mfw_openat
    global mfw_newfstatat
    global mfw_getdents
    global mfw_open
    global mfw_lstat
    global mfw_puts

    ;; Syscalls
mfw_write:
    mov eax, 0x01
    syscall
    ret

mfw_openat:
    mov eax, 0x101
    syscall
    ret

mfw_close:
    mov eax, 0x03
    syscall
    ret

mfw_exit:
    mov eax, 0x3c
    syscall
    ret

mfw_newfstatat:
    mov r10, rcx
    mov eax, 0x106
    syscall
    ret

mfw_getdents:
    mov eax, 78
    syscall
    ret

mfw_open:
    mov eax, 0x02
    syscall
    ret

mfw_lstat:
    mov eax, 0x06
    syscall
    ret

;; rdi -> string to print
mfw_puts:
    mov rsi, rdi ;; Put string on RSI as expected by write
    mov rdi, 1
    mov rdx, rdi
mfw_puts_10:
    cmp BYTE [rsi], 0
    jz mfw_puts_exit
    call mfw_write  ;; write (RDI, RSI, RDX)
    inc rsi
    jmp mfw_puts_10
mfw_puts_exit:
    xor rax,rax
        ret
