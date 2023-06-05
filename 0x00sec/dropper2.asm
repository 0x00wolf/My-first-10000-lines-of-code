BITS 64
            org 0x400000
    ehdr:                                           ; Elf32_Ehdr
                db      0x7F, "ELF", 2, 1, 1, 0     ; e_ident
        times 8 db      0
                dw      2                           ; e_type
                dw      0x3e                        ; e_machine
                dd      1                           ; e_version
                dq      _start                      ; e_entry
                dq      phdr - $$                   ; e_phoff
                dq      0                           ; e_shoff
                dd      0                           ; e_flags
                dw      ehdrsize                    ; e_ehsize
                dw      phdrsize                    ; e_phentsize
                dw      1                           ; e_phnum
                dw      0                           ; e_shentsize
                dw      0                           ; e_schnum
                dw      0                           ; e_shstrndx
    
    ehdrsize   equ     $ - ehdr
    
    phdr:                                           ; Elf32_Phdr
                dd      1                           ; p_type
                dd      5                           ; p_offset
            dq      0
                dq      $$                          ; p_vaddr
                dq      filesize                    ; p_filesz
                dq      filesize                    ; p_memsz
                dq      0x1000                      ; p_align

    phdrsize    eq      $ - phdr

        ;; compile
        ;; nasm -f bin -o fwget fwget.asm; chmod +x fwget

_start:
    push rbp
    mov rbp, rsp
    sub rsp, 1024 + 8 + 8 ; Read buffer + Socket + size

    ;; Variables
    ;; [rbp + 0x00] -> s (socket)
    ;; [rbp + 0x08] -> len (int)
    ;; [rbp + 0x10] -> buf (unsigned char)
    ;; Create socket
    ;; Find constants with: grep -R CONSTANT /usr/include
    ;; s = socket (PF_INET=2, SOCK_STREAM=1, IPPROTO_TCP=6);
    mov rdi, 2      ; PF_INET 2
    mov rsi, 1      ; SOCK_STREAM
    mov rdx, 6      ; IPPROTO_TCP
    call _socket

    mov [rbp + 0x00], rax
    cmp rax, 0
    jle error

    ;; connect (s [rbp+0], addr, 16)
    mov rdi, rax
    ;; mov rsi, 0x8c0aa8c011110002
    ;; mov rsi, 0x0100005f11110002
    lea rsi, [rel addr]
    mov rdx, 16
    call _connect
    test eax, eax
    jl error

10:         ; Read loop
    ;; Read data from socket
    ;; _read (s = [rbp + 0], [rbp + 0x10], 1024);
    mov rdi, [rbp + 0]
    lea rsi, [rbp+0x10]
    mov rdx, 1024
    call _read
    mov [rbp + 0x08], rax   ; Store number of bytres read
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
    mov rdi, [rbp + 0x00]   ;
    call _close

    mov rdi, 0      ; Success
    call _exit

error:
    ;; mov rdi, 2
    ;; lea rsi, [rel msg]
    ;; mov rdx, 7
    ;; call _write

    mov rdi, -1
    call _exit

    ;; Syscalls
_read:
    mov rax, 0
    jmp _do_syscall

_write:
    mov rax, 1
    jmp _do_syscall

_socket:
    mov rax, 41
    jmp _do_syscall

_connect:
    mov rax, 42
    jmp _do_syscall

_close:
    mov rax, 3
    jmp _do_syscall

_exit:
    mov rax, 60
    jmp _do_syscall

_do_syscall:
    syscall
    ret

addr dq 0x0100007f11110002
msg db "ERROR", 10,0
filesize equ $ - $$
