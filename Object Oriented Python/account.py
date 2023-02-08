class Account():
    def __init__(self, name, balance, password):
        self.name = name
        self.balance = int(balance)
        self.password = password

    def deposit(self, amountToDeposit, password):
        if password != self.password:
            print("Incorrect password.")
            return None
        if amountToDeposit < 0:
            print("You cannot deposit a negative amount.")
        self.balance = self.balance + amountToDeposit
        return self.balance

    def withdraw(self, amountToWithdraw, password):
        if password != self.password:
            print("Incorrect password.")
            return None
        if amountToWithdraw > self.balance:
            print("You cannot withdraw more than the balance of the account.")
            return None
        self.balance = self.balance - amountToWithdraw
        return self.balance
    
    def show(self):
        print('     Name: ', self.name)
        print('     Balance: ', self.balance)
        print('     Password: ', self.password)
        print()

    