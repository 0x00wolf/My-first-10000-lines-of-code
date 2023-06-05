    global mfw_select_target
    extern mfw_puts
    extern mfw_putln
    extern mfw_openat
    extern mfw_getdents
    extern mfw_close

    section .text

mfw_select_target:
    BUF_SIZE EQU    0x400
    FD       EQU    0x08
    BUF      EQU    (FD + BUF_SIZE)
    STE      EQU    BUF
    D_NAME   EQU    0x12
    D_RECLEN EQU    0x10

    push    rbp
    mov     rbp, rsp
    sub     rsp, STE
    ;; Open Directory
    ;; RDI and RSI should be all set
    mov     rdx, 0q200000      ;O_RDONLY | O_DIRECTORY
    call    mfw_openat
    mov     QWORD [rbp-FD], rax     ; Store fd in local var

loop0:
    mov     rdi, QWORD [rbp-FD]
    lea     rsi, [rbp-BUF]
    mov     rdx, BUF_SIZE
    call    mfw_getdents

    test    ax, ax
    jz      done
    js      loop0
    mov     r9, rax
    lea     r8, [rbp-BUF]       ; Points to struct linux_dirent record

loop1:
    lea     rdi, [r8 + D_NAME]  ; d_name in rdi
    call    mfw_putln

    mov     dx, WORD [r8 + D_RECLEN]    ; Get Record len
    sub     r9, rdx
    jz      loop0       ; If it is zero, get more data

    ;; Otherwise update pointers
    add     r8, rdx

    jmp     loop1

done:
    ;; Close directory
    mov     rdi, QWORD [rbp-FD]
    call    mfw_close
    leave               ; Set RSP=RBP and pops RBP
    ret
