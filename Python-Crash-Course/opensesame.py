def soup(filename):
    try:
        with open(filename, encoding='utf-8') as f:
            contents = f.read()
    except FileNotFoundError:
        pass
    else:
        contents.split()
        print(contents)

files = ['cats.txt', 'dogs.txt', 'dragons.txt']
for file in files:
    soup(file)