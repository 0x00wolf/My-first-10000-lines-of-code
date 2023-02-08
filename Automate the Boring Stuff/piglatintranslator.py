message = input("Input what you want converted to pig latin:\n")
words_in_message = message.split()
pig_latin = []
for words in words_in_message:
    prefix = words[0]
    words = words [1:]
    words = words + prefix + 'ay'
    pig_latin.append(words)
final_message = ' '.join(pig_latin)
print(final_message)