section .text
global _start

_start:
    push rbp
    mov rbp, rsp
    sub rsp, 1024 + 8 + 8 ; Read buffer + Socket + size

    ;; Variables
    ;; [rbp + 0x00] -> s (socket)
    ;; [rbp + 0x08] -> len (int)
    ;; [rbp + 0x10] -> buf (unsigned char)
    ;; Create socket
    ;; s = socket (PF_INET=2, SOCK_STREAM=1, IPPROTO_TCP=6);
    mov rdi, 2  ; PF_INET 2
    mov rsi, 1  ; SOCK_STREAM
    mov rdx, 6  ; IPPROTO_TCP
    mov r8, 10
    call _socket
    mov [rbp + 0x00], rax   ; Store socket in stack
    cmp rax, 0
    jle error

    ;; connect (s [rbp+0], addr, 16)
    mov rdi, rax
    lea rsi, [rel addr]
    mov rdx, 16
    mov r8, 20
    call _connect
    test eax, eax
    jl error

10: ; Read loop
    ;; Read data from socket
    ;; _read (s = [rbp + 0], [rbp + 0x10], 1024);
    mov rdi, [rbp + 0]
    lea rsi, [rbp+0x10]
    mov rdx, 1024
    call _read
    mov [rbp + 0x08], rax   ; Store number of bytes
    cmp rax, 0
    jle done

    ;; Write to stdout
    ;; _write (1, [rbp+0x10], [rbp+0x08])
    mov rdi, 1
    mov rdx, rax
    call _write
    cmp rax, 1024
    jl done
    jmp 10
done:
    ;; _close (s)
    mov rdi, [rbp + 0x00] ;
    call _close

    mov rdi, 0  ; Success
    call _exit

error:
    mov rdi, 2
    lea rsi, [rel msg]
    mov rdx, 7
    call _write

    mov rdi, r9
    add rdi, r8
    call _exit

    ;; Syscalls
_read:
    mov rax, 0
    syscall
    ret

_socket:
    mov rax, 41
    syscall
    ret

_connect:
    mov rax, 42
    syscall
    ret

_close:
    mov rax, 3
    syscall
    ret

_exit: 
    mov rax, 60
    syscall
    ret

addr dq 0x0100007f11110002
msg db "ERROR", 10,0
