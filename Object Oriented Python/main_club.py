# Club example main program
from class_club import *

# create a club with 5 members max
oClub = Club('Hellfire', 5)

oClub.addMember('Eddie')
oClub.addMember('Dustin')
oClub.addMember('Mike')
oClub.addMember('Lucas')
oClub.addMember('Gareth')
oClub.report()
oClub.addMember('Hoser')
oClub.maxMembers = 6
oClub.addMember('Freak')