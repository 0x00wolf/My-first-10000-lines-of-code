    ;; Select file

    global  _start
        extern  mfw_puts
        extern  mfw_exit

    section .text
_start:
        ;; Show welcome message
        mov rdi, wellcome_msg
        call mfw_puts

        ;; Call select_target

        ;; All done. Exiting
        xor rdi, rdi
        call mfw_exit

        ;; ===============
        section .data
wellcome_msg:   db      "Malware 0.1", 0x0a
