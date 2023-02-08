# pygame demo 2 - one image, click and move

# 1 - Import packages
import pygame
import sys
from pygame.locals import *
import random

# 2 - Define constants
BLACK = (0, 0, 0)
WINDOW_WIDTH = 640
WINDOW_HEIGHT = 480
FRAMES_PER_SECOND = 30
BALL_WIDTH_HEIGHT = 100
MAX_WIDTH = WINDOW_WIDTH - BALL_WIDTH_HEIGHT
MAX_HEIGHT = WINDOW_HEIGHT - BALL_WIDTH_HEIGHT

# 3 - Initialize pygame
pygame.init()
window = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))
clock = pygame.time.Clock()

# 4 - Load the assets
ballImage = pygame.image.load('images/ball.png')

# 5 - Initialize the variables
ballX = random.randrange(MAX_WIDTH)
ballY = random.randrange(MAX_HEIGHT)
ballRect = pygame.Rect(ballX, ballY, BALL_WIDTH_HEIGHT, BALL_WIDTH_HEIGHT)

# 6 - Looping times, forever
while True:

    # 7 - Check for the handle events
    for event in pygame.event.get():
        # Clicked the close button? Quit el pygame
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

        # See if the user clicked
        # another option = mouseX, mouseY = event.pos

        # Check if the click was in the rect of the ball
        # If so choose a random new location
        if event.type == pygame.MOUSEBUTTONUP:
            
            if ballRect.collidepoint(event.pos):
                ballX = random.randrange(MAX_WIDTH)
                ballY = random.randrange(MAX_HEIGHT)
                ballRect = pygame.Rect(ballX, ballY, BALL_WIDTH_HEIGHT,
                                       BALL_WIDTH_HEIGHT)
        
    # 8 - Do any per frame actions

    # 9 - Clear the screen
    window.fill(BLACK)

    # 10 - Draw all window elements
    window.blit(ballImage, (ballX, ballY))

    # 11 - Update the window
    pygame.display.update()

    # 12 - Slow things down a bit
    clock.tick(FRAMES_PER_SECOND)