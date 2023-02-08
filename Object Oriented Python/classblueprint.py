class MyClass():
    def __init__(self):
        self.count = 0 # Create self.count and set it to 0
    def increment(self):
        self.count = self.count + 1 
counter = MyClass()
print(counter)
for value in range(0, 10):
    counter.increment()
    print(counter.count)

# class <ClassName>():

#     def __init__(self, <optional param1>, ..., <optional paramN>):
#         # Any intialization code here

#     # Any number of functions that access the data
#     # Each has the form:

#     def <functionName1>(self, <optional param1>, ..., <optional paramN>):
#         # body of function

#     # ... more functions

#     def <functionNameN>(self, <optional param1>, ..., <optional paramN>):
#         # body of function

# <object> = <ClassName>(<optional arguments>)