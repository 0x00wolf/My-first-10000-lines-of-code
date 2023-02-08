# example to highlight elements of oop programming
class Person():
    def __init__(self, name, salary):
        self.name = name
        self.salary = salary

# getter
    def getSalary(self):
        return self.salary
    
# setter
    def setSalary(self, salary):
        self.salary = salary