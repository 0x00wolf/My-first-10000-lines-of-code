# 1 import modules
import pygame
from pygame.locals import *
import sys

# 2 set global vars
BLACK = (0, 0, 0)
WINDOW_WIDTH = 640
WINDOW_HEIGHT = 480
FRAMES_PER_SECOND = 30

# 3 - initialize pygame, the game window, and clock
pygame.init()
window = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))
clock = pygame.time.Clock()

# 4 - Load assets: image(s), sound(s), etc.
ballImage = pygame.image.load('images/ball.png')

# 5 - Initialize variables

# 6 - Loop forever
while True:

    # 7 - Check for handle events
    for event in pygame.event.get():
        # Clicked the close button? Quit pygame and end the prog.
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    # 8 - Do any "per frame" actions

    # 9 - Clear the window
    window.fill(BLACK)

    # 10 - Draw all window elements
    window.blit(ballImage, (100, 200))

    # 11 - Update the window
    pygame.display.update()

    # 12 - Slow things down a little
    clock.tick(FRAMES_PER_SECOND)