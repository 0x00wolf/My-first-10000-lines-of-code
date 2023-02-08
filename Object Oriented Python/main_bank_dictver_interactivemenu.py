from accountoop import *

accountsDict = {}
nextAccountNumber = 0

while True:
    print()
    print('Press b to get an account balance')
    print('Press d to make a deposit')
    print('Press w to make a withdrawal')
    print('Press o to open a new account')
    print('Press s to show all accounts')
    print('Press q to quit')
    print()

    action = input('Make a selection: ')
    action = action.lower()
    action = action[0]
    print()

    if action == 'b':
        print('***Get Balance***')
        userAccountNumber = input('What is your account number: ')
        userAccountNumber = int(userAccountNumber)
        userAccountPassword = input('Please enter your password: ')
        oAccount = accountsDict[userAccountNumber]
        theBalance = oAccount.get_balance(userAccountPassword)
        if theBalance is not None:
            print('Your balance is: ', theBalance)

    elif action == 'd':
        print('***Make Deposit***')
        userAccountNumber = input('What is your account number: ')
        userAccountNumber = int(userAccountNumber)
        userAccountPassword = input('Please enter your password: ')
        userDepositAmount = input('Input the amount you are depositing: ')
        userDepositAmount = int(userDepositAmount)
        oAccount = accountsDict[userAccountNumber]
        theBalance = oAccount.deposit(userDepositAmount, userAccountPassword)
        if theBalance is not None:
            print('The new balance is: ', theBalance)

    elif action == 'w':
        print('***Make Withdrawal***')
        userAccountNumber = input('What is your account number: ')
        userAccountNumber = int(userAccountNumber)
        userAccountPassword = input('Please enter your password: ')
        userWithdrawalAmount = input('Input the amount you are depositing: ')
        userWithdrawalAmount = int(userDepositAmount)
        oAccount = accountsDict[userAccountNumber]
        theBalance = oAccount.withdraw(userAccountPassword, userWithdrawalAmount)
        if theBalance is not None:
            print('The user withdrew: ', userWithdrawalAmount)
            print('The new balance is: ', theBalance)

    elif action == 'q':
        break

    elif action == 's':
        print('Show:')
        for userAccountNumber in accountsDict:
            oAccount = accountsDict[userAccountNumber]
            print('     Account number: ', userAccountNumber)
            oAccount.show()

    elif action == 'o':
        userName = input('What is the name on the account: ')
        userBalance = input('What is the amount along with opening the account: ')
        userPassword = input('What is your desired password for the account: ')
        oAccount = Account(userName, userBalance, userPassword)
        accountsDict[nextAccountNumber] = oAccount
        print('Your new account number is: ', nextAccountNumber)
        nextAccountNumber = nextAccountNumber + 1
        print()

    else:
        print("Sorry that was not a valid action, please try again.")
