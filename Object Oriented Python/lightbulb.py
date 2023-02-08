# Procedural lightswitch

def isOn():
    global lightswitchison
    # Turn on the lightswitch
    lightswitchison = True

def isOff():
    global lightswitchison
    # Turn off the lightswitch
    lightswitchison = False

isOn()
print("Lightswitch is on: ",lightswitchison)
isOff()
print("Lightswitch is on: ",lightswitchison)
isOn()
print("Lightswitch is on: ",lightswitchison)
isOff()
print("Lightswitch is on: ",lightswitchison)