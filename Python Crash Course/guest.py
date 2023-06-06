filename = './guest.txt'
prompt = "Input your name: "
guest = input(prompt)

with open(filename, 'w') as gg:
    gg.write(guest.title())