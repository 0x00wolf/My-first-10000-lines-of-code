import pygame
from pygame.sprite import Sprite

class Bullet(Sprite):
    """You shall not pass"""

    def __init__(self, ai_game):
    
        """Bullet x Steve Buscemi"""
        super().__init__()
        self.screen = ai_game.screen
        self.settings = ai_game.settings
        self.color = self.settings.bullet_color

        # Das rect
        self.rect = pygame.Rect(0, 0, self.settings.bullet_width, self.settings.bullet_height)
        self.rect.midtop = ai_game.ship.rect.midtop

        # Bullet's position
        self.y = float(self.rect.y)
    
    def update(self):
        """ Move b**** get out the way"""
        # Update das decimal position
        self.y -= self.settings.bullet_speed
        # Rect position
        self.rect.y = self.y

    def draw_bullet(self):
        """Draw da bulletz"""
        pygame.draw.rect(self.screen, self.color, self.rect)