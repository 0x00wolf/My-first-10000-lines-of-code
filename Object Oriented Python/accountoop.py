class Account():
    def __init__(self, name, balance, password):
        self.name = name
        self.balance = int(balance)
        self.password = password

    def deposit(self, depositAmount, password):
        if password != self.password:
            print("Incorrect password.")
            return None

        if depositAmount < 0:
            print("You cannot deposit a negative amount.")
            return None

        self.balance = self.balance + depositAmount
        return self.balance

    def withdraw(self, withdrawAmount, password):
        if password != self.password:
            print("Incorrect password.")
            return None

        if withdrawAmount < 0:
            print("You cannot withdraw a negative amount.")
            return None

        if withdrawAmount > self.balance:
            print("You cannot withdraw more than the balance.")
            return None

        self.balance = self.balance - withdrawAmount
        return self.balance

    def getBalance(self, password):
        if password != self.password:
            print("Incorrect password.")
            return None

        return self.balance

    def show(self):
        print('     Name: ', self.name)
        print('     Balance: ', self.balance)
        print('     Password: ', self.password)
        print()

    
    