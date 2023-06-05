    .global mfw_exit
    .global mfw_write
    .global mfw_close
    .global mfw_openat
    .global mfw_newfstatat
    .global mfw_getdents

mfw_write:
    mov $0x01, %eax
    syscall
    ret

mfw_openat:
    mov $0x101, %eax
    syscall
    ret

mfw_close:
    mov $0x03, %eax
    syscall
    ret

mfw_exit:
    mov $0x3c, %eax
    syscall
    ret

mfw_newfstatat:
    mov %rcx, %r10
    mov %0x106, %eax
    syscall
    ret

mfw_getdents:
    mov $78, %eax
    syscall
    ret

mfw_open:
    mov $0x02, %eax
    syscall
    ret

mfw_lstat:
    mov $0x06, %eax
    syscall
    ret
