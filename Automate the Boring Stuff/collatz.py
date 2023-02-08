from random import randint

def pick_number():
    the_number = randint(3,100)
    return the_number

def collatz(number):
    while number != 1:
        if number % 2 == 0:
            number = number // 2
            print(number)
        else: 
            number = number * 3 + 1
            print(number)        

a_number = pick_number()
collatz(a_number)