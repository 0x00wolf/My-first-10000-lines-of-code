from accountoop import *

class Bank():

    def __init__(self):
        self.accountsDict = {}
        self.nextAccountNumber = 0

    def createAccount(self, theName, theBalance, thePassword):
        oAccount = Account(theName, theBalance, thePassword)
        newAccountNumber = self.nextAccountNumber
        self.accountsDict[newAccountNumber] = oAccount
        # Increment in preparation for the next account to be added
        self.nextAccountNumber = self.nextAccountNumber + 1
        return newAccountNumber

    def openAccount(self):
        print('***Open Account***')
        userName = input('What is the name on the account: ')
        userStartingAmount = input('What is the starting balance for the account: $')
        userStartingAmount = int(userStartingAmount)
        userPassword = input('What is the password for the account: ')

        userAccountNumber = self.createAccount(userName, userStartingAmount, userPassword)
        print('Your new account number is: ', userAccountNumber)
        print()

    def closeAccount(self):
        print('***Close Account***')
        userAccountNumber = input('What is your account number: ')
        userAccountNumber = int(userAccountNumber)
        userPassword = input('What is your password: ')
        oAccount = self.accountsDict[userAccountNumber]
        theBalance = oAccount.getBalance(userPassword)
        if theBalance is not None:
            print('You had, $', theBalance, 'which will now be returned.')
            # Remove the user's account from the dictionary of accounts
            del self.accountsDict[userAccountNumber]
            print('Your account is now closed.')

    def balance(self):
        print('***Get Balance***')
        userAccountNumber = input('Please enter your account number: ')
        userAccountNumber = int(userAccountNumber)
        userAccountPassword = input('Please enter your password: ')
        oAccount = self.accountsDict[userAccountNumber]
        theBalance = oAccount.getBalance(userAccountPassword)
        if theBalance is not None:
            print("Your balance is: ", theBalance)

    def deposit(self):
        print('***Deposit Funds***')
        accountNum = input('Please enter your account number: ')
        accountNum = int(accountNum)
        accountPassword = input('Please enter your account password: ')
        depositAmount = input('Please enter the amount you would like to deposit: $')
        depositAmount = int(depositAmount)
        oAccount = self.accountsDict[accountNum]
        theBalance = oAccount.deposit(depositAmount, accountPassword)
        if theBalance is not None:
            print('Your new balance is: $', theBalance)
    
    def show(self):
        print('***Show***')
        for userAccountNumber in self.accountsDict:
            oAccount = self.accountsDict[userAccountNumber]
            print('     Account: ', userAccountNumber)
            oAccount.show()

    def withdraw(self):
        print('***Withdraw Funds***')
        userAccountNumber = input("What is your account number: ")
        userAccountNumber = int(userAccountNumber)
        userPassword = input("What is the password on your account: ")
        withdrawAmount = input("Withdrawal amount: $")
        withdrawAmount = int(withdrawAmount)
        oAccount = self.accountsDict[userAccountNumber]
        theBalance = oAccount.withdraw(withdrawAmount, userPassword)
        if theBalance is not None:
            print("Withdrew: $", withdrawAmount)
            print("Remaining balance: $", theBalance)
