# pygame docs referencing primitive shapes:
# http://www.pygame.org/docs/ref/draw.html

import pygame
from pygame.locals import *
import sys

WINDOW_WIDTH = 640
WINDOW_HEIGHT = 480
FRAMES_PER_SECOND = 30
GRAY = (175, 175, 175)
BLUE = (0, 0, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
YELLOW = (255, 255, 0)
TEAL = (0, 128, 128)

pygame.init()
window = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))
clock = pygame.time.Clock()

while True:

    # 7 - Check for handle events
    for event in pygame.event.get():
        # Clicked the close button? Quit pygame and end the program
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    # 8 - Do any "per frame" actions

    # 9 - Clear the window
    window.fill(GRAY)

    # 10 - Draw all the window elements
    # a box
    # pygame.draw.line(window, color, startpos, endpos, width=1)
    pygame.draw.line(window, BLUE, (20, 20), (60, 20), 4) # top
    pygame.draw.line(window, BLUE, (20, 20), (20, 60), 4) # left
    pygame.draw.line(window, BLUE, (20, 60), (60, 60), 4) # right
    pygame.draw.line(window, BLUE, (60, 20), (60, 60), 4) # bottom
    # Draw an X in the box
    pygame.draw.line(window, BLUE, (20, 20), (60, 60), 1)
    pygame.draw.line(window, BLUE, (20, 60), (60, 20), 1)

    # Draw a filled circle and an empty circle
    # pygame.draw.circle(window, color, pos, radius, width=0)
    pygame.draw.circle(window, GREEN, (250, 50), 30, 0) # filled
    pygame.draw.circle(window, GREEN, (400, 50), 30, 2) # 2 pixel edge
    
    # Draw a filled rectangle and an empty rectangle

    pygame.draw.rect(window, RED, (250, 150, 100, 50), 0) # filled
    pygame.draw.rect(window, RED, (400, 150, 100, 50), 1) # 1 pixel edge

    # Draw a filled ellipse and an empty ellipse
    # pygame.draw.ellipse(window, color, rect, width=0)
    pygame.draw.ellipse(window, YELLOW, (250, 250, 100, 50), 0) # filled
    pygame.draw.ellipse(window, YELLOW, (400, 250, 80, 40), 2) # 1 pixel edge
    
    # Draw a six-sided polygon
    # pygame.draw.polygon(window, color, pointslist, width=0)
    pygame.draw.polygon(window, TEAL, ((240, 350), (350, 350),
                                       (410, 410), (350, 470),
                                       (240, 470), (170, 410)))

    # Draw an arc
    # pygame.draw.arc(window, color, rect, angle_start, angle_stop, width=0)
    pygame.draw.arc(window, BLUE, (20, 400, 100, 100), 0, 2, 5)

    # Draw anti-aliased lines: a single line, then a list of points
    pygame.draw.aaline(window, RED, (500, 400), (540, 470), 1)
    pygame.draw.aalines(window, BLUE, True,
                        ((580, 400), (587, 450),
                         (595, 460), (600, 444)), 1)

    # 11 - Update the window
    pygame.display.update()

    # 12 - Slow things down a bit
    clock.tick(FRAMES_PER_SECOND) # Make pygame wait