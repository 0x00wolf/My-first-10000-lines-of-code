from account import  *

accountsDict = {}
nextAccountNumber = 0

# Create two accounts
oAccount = Account('HelloWorld', 1000, 'helloworld')
helloworldAccountNumber = nextAccountNumber
accountsDict[helloworldAccountNumber] = oAccount
nextAccountNumber = nextAccountNumber + 1

oAccount = Account('FooBarBaz', 1000, 'foobarbaz')
fooBarBazAccountNumber = nextAccountNumber
accountsDict[fooBarBazAccountNumber] = oAccount
nextAccountNumber = nextAccountNumber + 1

accountsDict[helloworldAccountNumber].show()
accountsDict[fooBarBazAccountNumber].show()
print()

userName = input("What is the name on the account?")
userBalance = input("What amount are you depositing?")
userBalance = int(userBalance)
userPassword = input("What is the password for the account")
oAccount = Account(userName, userBalance, userPassword)
newAccountNumber = nextAccountNumber
accountsDict[newAccountNumber] = oAccount
nextAccountNumber = nextAccountNumber + 1
accountsDict[newAccountNumber].show()
