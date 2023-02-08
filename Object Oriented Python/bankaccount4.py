# Non-oop, with lists
accountNamesList = []
accountBalancesList = []
accountPasswordsList = []

def newAccount(name, balance, password):
    global accountNameList, accountBalancesList, accountPasswordsList
    accountNamesList.append(name)
    accountBalancesList.append(balance)
    accountPasswordsList.append(password)

def show(accountNumber):
    global accountNameList, accountBalancesList, accountPasswordsList
    print('Account ', accountNumber)
    print('       Name: ', accountNamesList[accountNumber])
    print('       Balance: ', accountBalancesList[accountNumber])
    print('       Password: ', accountPasswordsList[accountNumber])
    print()

def getBalance(accountNumber, password):
    global accountNameList, accountBalancesList, accountPasswordsList
    if password != accountPasswordsList[accountNumber]:
        print('Incorrect password')
        return None
    return accountBalancesList[accountNumber]

