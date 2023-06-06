print("Give me two numbers to add, 'q' to quit.")
while True:
    number1 = input("Number one: ")
    if number1 == 'q':
        break
    number2 = input("Number two: ")
    if number2 == 'q':
        break
    try:
        answer = (int(number1) + int(number2))
    except ValueError:
        print("I can only add numbers")
    else:
        print(answer)