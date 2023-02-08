# Single account version
account_name = ''
account_balance = 0
account_password = ''

def new_account(name, balance, password):
    global account_name, account_balance, account_password
    account_name = name
    account_balance = balance
    account_password = password

def show():
    global account_name, account_balance, account_password
    print(f'\n     Name: {account_name}')
    print(f'     Balance: {account_balance}')
    print(f'     Password: {account_password}\n')

def get_balance(password):
    global account_password, account_balance, account_name
    if password != account_password:
        print('Incorrect password')
        return None
    else:
        return account_balance

def get_deposit(amount_to_deposit, password):
    global account_name, account_balance, account_password
    if amount_to_deposit < 0:
        print("You cannot deposit a negative amount.")
        return None

    if password != account_password:
        print("Wrong password")
        return None

    account_balance = account_balance + amount_to_deposit
    return account_balance

def withdraw(amount_to_withdraw, password):
    global account_name, account_balance, account_password
    if amount_to_withdraw < 0:
        print("You cannot withdraw a negative amount")
        return None
    
    if password != account_password:
        print("Wrong password bud.")
        return None
    
    if amount_to_withdraw > account_balance:
        print("You don't have overdraft protection bud.")
        return None

    account_balance = account_balance - amount_to_withdraw
    return account_balance

new_account("Bob", 100, 'soupnazi')

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
        the_balance = get_balance(user_password)
        if the_balance is not None:
            print(f"Your balance is {the_balance}.")
        
    elif action == 'd':
        print("Make a deposit:")
        deposit_amount = input("How much would you like to deposit: ")
        deposit_amount = int(deposit_amount)
        user_password = input("Input password: ")
        new_balance = get_deposit(deposit_amount, user_password)
        if new_balance is not None:
            print(f"New balance: {account_balance}.")

    elif action == 's':
        print('Show account:')
        user_password = input("Input password: ")
        if user_password != account_password:
            print('Incorrect password')

        
    elif action == 'q':
        break

    elif action == 'w':
        print("Make a withdrawal:")
        withdrawal_amount = input("How much would you like to deposit: ")
        withdrawal_amount = int(withdrawal_amount)
        user_password = input("Input password: ")
        new_balance = 
            print(f"New balance: {account_balance}.")

print("Hasta la vista, baby!")