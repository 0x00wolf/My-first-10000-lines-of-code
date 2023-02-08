# Three classes with the same named methods

class Dog():
    def __init__(self, name):
        self.name = name

    def speak(self):
        print(self.name, ' says bark, bark, bark!')

class Cat():
    def __init__(self, name):
        self.name = name

    def speak(self):
        print(self.name, ' says meow, meow!')

class Bird():
    def __init__(self, name):
        self.name = name

    def speak(self):
        print(self.name, ' says tweet, tweet!')

oDog1 = Dog('Rover')
oDog2 = Dog('Fido')
oCat1 = Cat('Fluffer')
oCat2 = Cat('Sparkles')
oBird1 = Bird('Tweety')
oBird2 = Bird('Zoomer')

petsList = [oDog1, oDog2, oCat1, oCat2, oBird1, oBird2]

for oPet in petsList:
    print(oPet.speak())