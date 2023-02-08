from accountoop import *

userName = input("Enter username for account")
userBalance = input("Enter amount deposited.")
userBalance = int(userBalance)
userPassword = input("Enter your new password.")
oAccount3 = Account(userName, userBalance, userPassword)

oAccount1 = Account('Hello World', 1000, 'helloworld')
oAccount2 = Account('Foo Bar Baz', 1000, 'foobarbaz')

oAccount1.deposit(1600, 'helloworld')
oAccount2.withdraw(500, 'foobarbaz')
accounts = []
accounts.append(oAccount1)
accounts.append(oAccount2)
accounts.append(oAccount3)
for account in accounts:
    account.show()