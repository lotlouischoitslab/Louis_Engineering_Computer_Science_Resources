import pygame 
import os

# Dimensions for the pygame window
WIDTH,HEIGHT = 900,500
WIN = pygame.display.set_mode((WIDTH,HEIGHT))
pygame.display.set_caption('First Game!')

WHITE = (255,255,255)

# Spaceship Information
FPS = 60
SPACESHIP_WIDTH,SPACESHIP_HEIGHT = 55,40

YELLOW_SPACESHIP_IMAGE = pygame.image.load(os.path.join('Assets','spaceship_yellow.png'))
YELLOW_SPACESHIP_IMAGE = pygame.transform.scale(YELLOW_SPACESHIP_IMAGE,(SPACESHIP_WIDTH,SPACESHIP_HEIGHT))
YELLOW_SPACESHIP_IMAGE = pygame.transform.rotate(pygame.transform.scale(YELLOW_SPACESHIP_IMAGE,(SPACESHIP_WIDTH,SPACESHIP_HEIGHT)),90)

RED_SPACESHIP_IMAGE = pygame.image.load(os.path.join('Assets','spaceship_red.png'))
RED_SPACESHIP_IMAGE = pygame.transform.scale(RED_SPACESHIP_IMAGE,(SPACESHIP_WIDTH,SPACESHIP_HEIGHT))
RED_SPACESHIP_IMAGE = pygame.transform.rotate(pygame.transform.scale(RED_SPACESHIP_IMAGE,(SPACESHIP_WIDTH,SPACESHIP_HEIGHT)),270)


# Functions to be implemented
def draw_window(red,yellow):
    WIN.fill(WHITE) #fill the background as white
    WIN.blit(YELLOW_SPACESHIP_IMAGE,(yellow.x,yellow.y)) #draw yellow spaceship on the screen
    WIN.blit(RED_SPACESHIP_IMAGE,(red.x,red.y)) #draw red spaceship on the screen
    pygame.display.update() #update the display

def main():
    red = pygame.Rect(700,300,SPACESHIP_WIDTH,SPACESHIP_HEIGHT)
    yellow = pygame.Rect(100,300,SPACESHIP_WIDTH,SPACESHIP_HEIGHT)

    clock = pygame.time.Clock()
    run = True 
    while run:
        clock.tick(FPS)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False

        keys_pressed = pygame.key.get_pressed()
        if keys_pressed[pygame.K_a]: #Left key
            yellow.x -= VEL
        

        draw_window(red,yellow)

    pygame.quit()

if __name__ == '__main__':
    main()