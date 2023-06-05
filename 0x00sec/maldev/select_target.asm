    global mfw_select_target
    extern mfw_puts
    extern mfw_openat
    extern mfw_getdents
    extern mfw_close

    section .text
mfw_select_target:
    push rbp
    mov rbp, rsp
    sub rsp, 0x10

    ;; Our code goes here

    leave       ; Set RSP = RBP and pops RBP
    ret
