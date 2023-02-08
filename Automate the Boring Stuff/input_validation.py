age = input('What is your age?\nAnswer: ')
while True:
    try:
        age = int(age)
    except:
        print("Please input a numeric value")
    if age < 1:
        print("You can't be negative years old...")
        continue
    break
print(f'Hello user who is {age} years old.')