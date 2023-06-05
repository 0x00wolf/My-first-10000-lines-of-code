i = 0
while i < 100:
    i += 1
    if (i % 3) == 0 and (i % 5) == 0:
        print('buzz')
    elif (i % 3) == 0:
        print('fizz')
    else:
        print(i)
