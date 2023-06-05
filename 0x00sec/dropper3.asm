BITS 64
;;; ELF header.... we make use of the 8 bytes available in the header
	org 0x400000
BUF_SIZE:	equ 1024
  ehdr:                                                 ; Elf64_Ehdr
                db      0x7F, "ELF", 2, 1, 1, 0         ;   e_ident
_start:
  	            xor edi,edi		; 31 ff  - Sets EDI to 0
	            inc edi         ; ff c7  - Sets EDI to 1
	            push rdi		; 57
	            pop  rsi		; 5e     - Sets RSO to 1
	            jmp _start1		; eb XX 


                dw      2                               ;   e_type
                dw      0x3e                            ;   e_machine
                dd      1                               ;   e_version
                dq      _start                          ;   e_entry
                dq      phdr - $$                       ;   e_phoff
                dq      0                               ;   e_shoff
                dd      0                               ;   e_flags
                dw      ehdrsize                        ;   e_ehsize
                dw      phdrsize                        ;   e_phentsize
                dw      1                               ;   e_phnum
                dw      0                               ;   e_shentsize
                dw      0                               ;   e_shnum
                dw      0                               ;   e_shstrndx
  
  ehdrsize      equ     $ - ehdr
  
  phdr:                                                 ; Elf32_Phdr
                dd      1                               ;   p_type
                dd      5                               ;   p_offset
	        dq      0
                dq      $$                              ;   p_vaddr
                dq      $$                              ;   p_paddr
                dq      filesize                        ;   p_filesz
                dq      filesize                        ;   p_memsz
                dq      0x1000                          ;   p_align
  
  phdrsize      equ     $ - phdr

	;;  Compile
	;; nasm -f bin -o fwget fwget.asm; chmod +x fwget

_start1:
	inc edi                 ; Set EDI to 2
	mov edx, 6              ; IPPROTO_TCP
	
	;; socket (AF_INET=2, SOCK_STREAM = 1, IPPROTO_TCP=6)
	call _socket
	mov ebx, eax		; Store socket on ebx
	;;  It is unlikely that the socket syscall will fail. No check for errors

	;; connect (s [rbp+0], addr, 16)
	mov edi, eax		; Saves 1 byte
	lea rsi, [rel addr]
	add edx,10
	
	call _connect
	;;	Just skip error check... if it fails is not gonna work anyway
	
	lea rsi, [rsp]	 ; Just use the stack as buffer.... we should decrement it
l0:				; Read loop
	;; Read data from socket
	;; _read (s = rbx, buf= [rsp], 1024);

	mov edi, ebx
	mov edx, BUF_SIZE
	call _read
	cmp eax, 0
	jle done

	;; Write to stdout
	;; _write (1, [rsp], rax)
	xor edi,edi
	inc edi			; rdi = 1
	mov edx, eax		; get len from _read
	call _write
	cmp eax, BUF_SIZE
	jl done
	jmp l0
done:
	;;  _close (s)
	;;	File descriptors get closed automatically when the process dies

	;; We do not care about exit code
	call _exit		
	
	;; Syscalls
_read:
	xor eax,eax
	jmp _do_syscall
	
_write:
	xor eax,eax
	inc eax

	jmp _do_syscall
	
_socket:
	;; mov rax, 41
	xor eax,eax
	add al, 41
	jmp _do_syscall
	
_connect:
	;; 	mov rax, 42
	xor eax,eax
	add al, 42
	jmp _do_syscall
	
_close:
	;; mov rax, 3
	xor eax,eax
	add al, 3
	jmp _do_syscall
	
_exit:
	xor eax,eax
	add al, 60

_do_syscall:
	syscall
	ret
	
addr dq 0x0100007f11110002
filesize equ $ - $$
