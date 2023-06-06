filename = './guest_book.txt'
bob = True
while bob == True:
    prompt = "Input your name (q to quit): "
    guest = input(prompt)
    if guest == 'q':
        bob = False
    else:
        with open(filename, 'a') as gg:
            gg.write(guest.title() + "\n")
