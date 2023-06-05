select_asm01: select_file01.asm minilibc2.asm select_target.asm
	ld -o $@ $^

%.o: %.asm
	nasm -f elf64 -o $@ $^
