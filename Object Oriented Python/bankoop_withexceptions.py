from accountoop_withexceptions import *
# Bank that manages a dictionary of account objects

class Bank():
    def __init__(self, hours, address, phone):
        self.accountsDict = {}
        self.nextAccountNumber = 0
        self.hours = hours
        self.address = address
        self.phone = phone

    def askForValidAccountNumber(self):
        accountNumber = input('What is your account number: ')
        try:
            accountNumber = int(accountNumber)
        except ValueError:
            raise AbortTransaction('The account must be an integer.')
        if accountNumber not in self.accountsDict:
            raise AbortTransaction('There is no account ', + str(accountNumber))
        return accountNumber
    
    def getUsersAccount(self):
        accountNumber = self.askForValidAccountNumber()
        oAccount = self.accountsDict[accountNumber]
        self.askForValidPassword(oAccount)
        return oAccount

    ###Snipped methods

    def deposit(self):
        print('***Print***')
        oAccount = self.getUsersAccount()
        depositAmount = input('Please enter amount to deposit: ')
        theBalance = oAccount.deposit(depositAmount)
        print('Deposited: ', depositAmount)
        print('Your new balance is: ', theBalance)

    def withdraw(self):
        print('***Withdraw***')
        oAccount = self.getUsersAccount()
        userAmount = input('Please enter the amount to withdraw: ')
        theBalance = oAccount.withdraw(userAmount)
        print('Withdrew: ', userAmount)
        print('New balance: ', theBalance)

    def getInfo(self):
        print('Hours: ', self.hours)
        print('Address: ', self.address)
        print('Phone: ', self.phone)
        print('We currently have ', len(self.accountsDict), 'account(s) open.')

    # Special method for bank admin only
    def show(self):
        print('***Show***')
        print('(This would normally require an admin password)')
        for userAccountNumber in self.accountsDict:
            oAccount = self.accountsDict[userAccountNumber]
            print('Account: ', userAccountNumber)
            oAccount.show()
            print()