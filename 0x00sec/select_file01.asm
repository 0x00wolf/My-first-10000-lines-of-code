        ;; Select file
    global _start
        ;; List the functions we will use
        extern mfw_puts
        extern mfw_exit

    section .text
_start:
        ;; Show welcome message
        mov rdik wellcome_msg
        call mfw_puts

        ;; Call select_target

        ;; All done. Exiting
        xor rdi, rdi
        call mfw_exit

        ;; -------------------------
        section .data
wellcome_msg:   db      "Malware 0.1", 0x0a
