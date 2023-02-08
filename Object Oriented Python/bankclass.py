from accountoop import *

class Bank():

    def __init__(self):
        self.accountsDict = {}
        self.nextAccountNumber = 0

    def createAccount(self, theName, theStartingAmount, thePassword):
        oAccount = Account(theName, theStartingAmount, thePassword)
        newAccountNumber = self.nextAccountNumber
        self.accountsDict[newAccountNumber] = oAccount
        # Increment the value of nextaccountnumbet to prepare for the next account
        self.nextAccountNumber = self.nextAccountNumber + 1
        return newAccountNumber

    def openAccount(self):
        print('***Open Account***')
        userName = input('What is the name for the new user account?')
        userStartingAmount = input('Amount deposited with opening of account: ')
        userStartingAmount = int(userStartingAmount)
        userPassword = input('What is the user password: ')

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
            print('You had ', theBalance, ' which has now been returned.')
            del self.accountsDict[userAccountNumber]
            print('Your account is now closed')

    def balance(self):
        print('***Get Balance***')
        userAccountNumber = input('Please enter your account number: ')
        userAccountNumber = int(userAccountNumber)
        userAccountPassword = input('Please enter your password: ')
        oAccount = self.accountsDict[userAccountNumber]
        theBalance = oAccount.getBalance(userAccountPassword)
        if theBalance is not None:
            print('Your balance is: ', theBalance)

    def deposit(self):
        print('***Deposit***')
        accountNumber = input('Please enter your account number: ')
        accountNumber = int(accountNumber)
        depositAmount = input('Please enter the amount you will deposit')
        depositAmount = int(depositAmount)
        userAccountPassword = input('Please enter your password: ')
        oAccount = self.accountsDict[accountNumber]
        theBalance = oAccount.deposit(depositAmount, userAccountPassword)
        if theBalance is not None:
            print('Your new balance is ', theBalance)

    def show(self):
        print('***Show***')
        for userAccountNumber in self.accountsDict:
            oAccount = self.accountsDict[userAccountNumber]
            print('     Account: ', userAccountNumber)
            oAccount.show()

    def withdraw(self):
        print('***Withdraw***')
        userAccountNumber = input('Please enter your account number: ')
        userAccountNumber = int(userAccountNumber)
        userAmount = input('Enter the amount you would like to withdraw: ')
        userAmount = int(userAmount)
        userAccountPassword = input('Please enter the password: ')
        oAccount = self.accountsDict[userAccountNumber]
        theBalance = oAccount.withdraw(userAmount, userAccountPassword)
        if theBalance is not None:
            print('Withdrew: ', userAmount)
            print('Your new balance is: ', theBalance)