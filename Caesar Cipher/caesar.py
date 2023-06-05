upper = {ascii:chr(ascii) for ascii in range(65, 91)}
lower = {ascii:chr(ascii) for ascii in range(97, 123)}

def print_char(character):
    print(character, end='')

def solve(msg, key):
    for character in msg:
        if character.isalpha():
            output = ord(character)
            if output in upper and output - key % 26 in upper:
                print_char(chr(output - key % 26))
            elif output in lower and output - key % 26 in lower:
                print_char(chr(output - key % 26))
            else:
                print_char(character)

print('\n' * 40 + 'Caesar Cipher')
prompt1 = input("Msg: ")
prompt2 = int(input("Key: "))
solve(prompt1, prompt2)
