# Main program for controlling a bank made up of accounts

# Bring in all the code from the bank class
from bank_oop_SeperateBankClass import *

# Create an instance of the bank
oBank = Bank()

# Main code
# Create two test accounts
joesAccountNumber = oBank.createAccount('Joe', 100, 'joespassword')
print("Joe's account number is: #", joesAccountNumber, ".")

marysAccountNumber = oBank.createAccount('Mary', 12345, 'maryspassword')
print("Mary's account number is: #", marysAccountNumber, ".")

while True:
    print()
    print("To get an account balance, print 'b'.")
    print("To make a deposit, print 'd'.")
    print("To make a withdrawal, print 'w'.")
    print("To open a new account, press 'o'.")
    print("To quit, press 'q'.")
    print("To show all accounts, press 's'.")
    print("To close an account, press 'c'.")
    print()

    action = input('Make a selection: ')
    action = action.lower()
    action = action[0]
    print()

    if action == 'b':
        oBank.balance()

    elif action == 'd':
        oBank.deposit()
    
    elif action == 'c':
        oBank.closeAccount()

    elif action == 'o':
        oBank.openAccount()

    elif action == 's':
        oBank.show()

    elif action == 'q':
        break

    elif action == 'w':
        oBank.withdraw()

    else:
        print("That is not a valid option. Try again.")

print("Done")
