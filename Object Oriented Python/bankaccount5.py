# non-OOP version
# dictionary implementation of a bank account
accountsList = []

def newAccount(aName, aBalance, aPassword):
    global accountsList
    newAccountDict = {'name':aName, 'balance':aBalance, 'password':aPassword}
    accountsList.append(newAccountDict)

def show(accountNumber):
    global accountsList
    print('Account-', accountNumber)
    thisAccountDict = accountsList[accountNumber]
    print('       Name: ', thisAccountDict['name'])
    print('       Balance: ', thisAccountDict['balance'])
    print('       Password: ', thisAccountDict['password'])
    print()

def getBalance(accountNumber, password):
    global accountsList
    thisAccountDict = accountsList[accountNumber]
    if password != thisAccountDict['password']:
        print('Incorrect password')
        return None
    return thisAccountDict['balance']

def deposit(accountNumber, password, amount):
    global accountsList
    thisAccountDict = accountsList[accountNumber]
    if password!= thisAccountDict['password']:
        print ('Incorrect password')
        return None
    thisAccountDict['balance'] += amount
    return thisAccountDict['balance']

def withdraw(accountNumber, password, amount):
    global accountsList
    thisAccountDict = accountsList[accountNumber]
    if password != thisAccountDict['password']:
        print('Incorrect password')
        return None
    if amount > thisAccountDict['balance']:
        print("Insufficient funds!")
        return None
    thisAccountDict['balance'] -= amount
    return thisAccountDict['balance']

print("Joe's account number is: ", len(accountsList))
newAccount("Joe", 100, 'soup')
print("Susan's account number is: ", len(accountsList))
newAccount("Susan", 10000, 'nuts')

while True:
    print()
    print('Press b to get the balance')
    print('Press d to make a deposit')
    print('Press w to make a withdrawal')
    print('Press n to create a new account')
    print('Press s to show all accounts')
    print('Press q to quit')
    print()

    action = input('Make your selection: ')
    action = action.lower()
    action = action[0]
    print()

    if action == 'b':
        print('Get balance')
        userAccountNumber = input("Please enter your account number: ")
        userAccountNumber = int(userAccountNumber)
        userPassword = input("Please enter your account password: ")
        theBalance = getBalance(userAccountNumber, userPassword)
        if theBalance is not None:
            print('Your balance is: ', theBalance)

    if action == 'd':
        print('Deposit: ')
        userAccountNumber = input("Please enter your account number: ")
        userAccountNumber = int(userAccountNumber)
        userPassword = input("PLease enter your account password: ")
        depositAmount = input("Please enter the amount to deposit: ")
        depositAmount = int(depositAnount)
        newBalance = deposit(userAccountNumber, userPassword, depositAmount)
        if newBalance is not None:
            print('Your balance is now: ', newBalance)

    if action == 'w':
        print('Withdrawal amount: ')
        userAccountNumber = input("Please enter your account number: ")
        userAccountNumber = int(userAccountNumber)
        userPassword = input("Please enter your account password: ")
        withdrawalAmount = input("Please enter ")
        withdrawalAmount = int(withdrawalAmount)
        newBalance = withdraw(userAccountNumber, userPassword, withdrawalAmount)
        if newBalance is not None:
            print('Your balance is now: ', newBalance)

    if action == 'n':
        accountNumber = len(accountsList)
        print("Your new account number is: ", accountNumber)
        accountName = input("Please enter your name: ")
        while True:
            accountPassword = input("Please enter your password: ")
            confirmPassword = input("Please confirm your password: ")
            if accountPassword != confirmPassword:
                print("Your passwords do not match, try again.")
            else:
                break
        initialBalance = input("Amount to deposit: ")
        initialBalance = int(initialBalance)
        accountCreated = newAccount(accountName, initialBalance, accountPassword)

    if action == 's':
        for account in accountsList:
            name = account['name']
            balance = account['balance']
            password = account['password']
            print(f"Name: {name}, Balance: ${balance}, Password: {password}")

        
        
            


