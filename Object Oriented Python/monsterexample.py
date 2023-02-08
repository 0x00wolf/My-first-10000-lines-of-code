import random

class Monster():
    def __init__(self, nRows, nCols, maxSpeed):
        self.nRows = nRows
        self.nCols = nCols
        self.myRow = random.randrange(self.nRows) # Choose a random row
        self.myCol = random.randrange(self.nCols) # Choose a random column
        self.mySpeedX = random.randrange(-maxspeed, maxspeed + 1) # Chooses a x speed
        self.mySpeedY = random.randrange(-maxspeed, maxspeed + 1) # Chooses a y speed
        # Set other instance variables like health, power, etc.

    def move(self):
        self.myRow = (self.myRow + self.mySpeedY) % self.nRows
        self.myCol - (self.myCol + self.mySpeedX) % self.nRows

N_MONSTERS = 20
N_ROWS = 100    # could be any size
N_COLS = 200    # could be any size
MAX_SPEED = 4
monsterList = []# start with an empty list
for i in range(N_MONSTERS):
    oMonster = Monster(N_ROWS, N_COLS, MAX_SPEED)
    monsterList.append(oMonster)