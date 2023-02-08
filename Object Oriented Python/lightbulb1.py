class lightSwitch():
    
    def __init__(self):
        self.switchIsOn = False
        self.brightness = 0

    def turnOn(self):
        # Turn on the light switch
        self.switchIsOn = True

    def turnOff(self):
        # Turn off the light switch
        self.switchIsOn = False

    def raiseLevel(self):
        if self.brightness < 10:
            self.brightness = self.brightness + 1
        
    def lowerLevel(self):
        if self.brightness > 0:
            self.brightness = self.brightness - 1

    def show(self):
        print('Is the switch on? ', self.switchIsOn)
        print('Brightness is: ', self.brightness)

lightSwitch1 = lightSwitch()
lightSwitch2 = lightSwitch()
lightSwitch2.turnOn()
lightSwitch1.turnOn()
print("Lightswitch 1 is on? ", lightSwitch1.switchIsOn)
print("Lightswitch 2 is on? ", lightSwitch2.switchIsOn)
lightSwitchs = []
lightSwitchs.append(lightSwitch1)
lightSwitchs.append(lightSwitch2)
for light in lightSwitchs:
    light.turnOff()
    print("The light is on? ", light.switchIsOn)
for light in lightSwitchs:
    light.show()
for light in lightSwitchs:
    for value in range(6):
        light.raiseLevel()
    print(light.show())