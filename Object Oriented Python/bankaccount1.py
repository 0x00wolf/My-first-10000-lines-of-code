# Single account version
account_name = 'joe'
account_balance = 100
account_password = 'soup'

while True:
    print("\nPress 'b' to get the balance.")
    print("Press 'd' to make a deposit.")
    print("Press 'w' make a withdrawal.")
    print("Press 's' to show the account.")
    print("Press 'q' to quit.\n")

    action = input("What do you want to do?")
    action = action.lower()
    action = action[0]
    print()

    if action == 'b':
        print('Get balance: ')
        user_password = input("Input password: ")
        if user_password != account_password:
            print('Incorrect password')
        else:
            print(f"Your balance is {account_balance}.")
        
    elif action == 'd':
        print("Make a deposit:")
        deposit_amount = input("How much would you like to deposit: ")
        deposit_amount = int(deposit_amount)
        user_password = input("Input password: ")
        if user_password != account_password:
            print('Incorrect password')
        else:
            if deposit_amount < 0:
                print("You cannot deposit a negative amount.")
            else:
                account_balance = account_balance + deposit_amount
                print(f"New balance: {account_balance}.")

    elif action == 's':
        print('Show account:')
        user_password = input("Input password: ")
        if user_password != account_password:
            print('Incorrect password')
        else:
            print(f'     Name: {account_name}')
            print(f'     Balance: {account_balance}')
            print(f'     Password: {account_password}\n')
        
    elif action == 'q':
        break

    elif action == 'w':
        print("Make a withdrawal:")
        withdrawal_amount = input("How much would you like to deposit: ")
        withdrawal_amount = int(withdrawal_amount)
        user_password = input("Input password: ")
        if user_password != account_password:
            print('Incorrect password')
        elif withdrawal_amount > account_balance:
            print("You cannot withdraw more than your account balance.")   
        elif withdrawal_amount < 0:
            print("You must withdraw a positive amount.")
        else:
            account_balance = account_balance - deposit_amount
            print(f"New balance: {account_balance}.")

print("Hasta la vista, baby!")