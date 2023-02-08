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
TARGET_X = 400
TARGET_Y = 320
TARGET_WIDTH_HEIGHT = 120
N_PIXELS_TO_MOVE = 3

# 3 - Initialize pygame
pygame.init()
window = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))
clock = pygame.time.Clock()

# 4 - Load the assets
ballImage = pygame.image.load('images/ball.png')
targetImage = pygame.image.load('images/target.jpg')

# 5 - Initialize the variables
ballX = random.randrange(MAX_WIDTH)
ballY = random.randrange(MAX_HEIGHT)
targetRect = pygame.Rect(TARGET_X, TARGET_Y, TARGET_WIDTH_HEIGHT, TARGET_WIDTH_HEIGHT)

# 6 - Looping times, forever
while True:

    # 7 - Check for the handle events
    for event in pygame.event.get():
        # Clicked the close button? Quit el pygame
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

        #Keyboard polling
    keyPressedTuple = pygame.key.get_pressed()

    if keyPressedTuple[pygame.K_LEFT]:
        ballX = ballX - N_PIXELS_TO_MOVE
    if keyPressedTuple[pygame.K_DOWN]:
        ballY = ballY + N_PIXELS_TO_MOVE
    if keyPressedTuple[pygame.K_RIGHT]:
        ballX = ballX + N_PIXELS_TO_MOVE
    if keyPressedTuple[pygame.K_UP]:
        ballY = ballY - N_PIXELS_TO_MOVE
            
    # 8 - Do any per frame actions
    ballRect = pygame.Rect(ballX, ballY, 
                           BALL_WIDTH_HEIGHT, BALL_WIDTH_HEIGHT)
    if ballRect.colliderect(targetRect):
        print('Ball is touching the target')

    # 9 - Clear the screen
    window.fill(BLACK)

    # 10 - Draw all window elements
    window.blit(ballImage, (ballX, ballY))
    window.blit(targetImage, (TARGET_X, TARGET_Y))

    # 11 - Update the window
    pygame.display.update()

    # 12 - Slow things down a bit
    clock.tick(FRAMES_PER_SECOND)