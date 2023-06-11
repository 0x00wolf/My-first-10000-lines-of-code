import pygame
from pygame.sprite import Sprite

class Alien(Sprite):
    """A class to represent an Alien ship"""
    def __init__(self, ai_game):
        """Initialize alien and set its starting position."""
        super().__init__()
        self.screen = ai_game.screen
        self.settings = ai_game.settings

        # Load the image and set its rect attribute.
        self.image = pygame.image.load('images/alien.bmp')
        self.rect = self.image.get_rect()

        # Start each new alien near the top left of the screen
        self.rect.x = self.rect.width
        self.rect.y = self.rect.height

        # Store the alien's exact horizontal position
        self.x = float(self.rect.x)

    def check_edges(self):
        """Return True if alien is at the edge of screen."""
        screen_rect = self.screen.get_rect()
        if self.rect.right >= screen_rect.right or self.rect.left <= 0:
            return True

    def update(self):
        """Move to da right."""
        self.x += (self.settings.alien_speed * 
                        self.settings.fleet_direction)
        self.rect.x = self.x