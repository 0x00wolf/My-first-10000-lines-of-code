from class_person import *

# person example main program using getters and setters

oPerson1 = Person('Joey', 90000)
oPerson2 = Person('Chandler', 100000)

# Get the salaries with the getter method
print(oPerson1.getSalary())
print(oPerson2.getSalary())

# Change the salaries using the setter
oPerson1.setSalary(1090000)
oPerson2.setSalary(20202020)

# Get the salaries and print again
print(oPerson1.getSalary())
print(oPerson2.getSalary())