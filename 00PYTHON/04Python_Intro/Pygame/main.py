import pygame 
import os

# Dimensions for the pygame window
WIDTH,HEIGHT = 900,500
WIN = pygame.display.set_mode((WIDTH,HEIGHT))
pygame.display.set_caption('First Game!')

# White background screen
WHITE = (255,255,255)
BLACK = (0,0,0)

# Borderlines
BORDER = pygame.Rect(WIDTH/2 - 5,0,10,HEIGHT)

# Spaceship Information
FPS = 60
vel = 5
BULLET_VEL = 7
MAX_BULLETS = 3
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
    pygame.draw.rect(WIN,BLACK,BORDER) #draw a rectangle
    WIN.blit(YELLOW_SPACESHIP_IMAGE,(yellow.x,yellow.y)) #draw yellow spaceship on the screen
    WIN.blit(RED_SPACESHIP_IMAGE,(red.x,red.y)) #draw red spaceship on the screen
    pygame.display.update() #update the display


# Handle Control functions implemented below
def yellow_handle_movement(keys_pressed,yellow):
    if keys_pressed[pygame.K_LEFT] and yellow.x-vel > 0: #LEFT
        yellow.x -= vel 
    if keys_pressed[pygame.K_RIGHT] and yellow.x+vel + yellow.width < BORDER.x: #RIGHT
        yellow.x += vel
    if keys_pressed[pygame.K_UP] and yellow.y - vel > 0: #UP
        yellow.y -= vel 
    if keys_pressed[pygame.K_DOWN] and yellow.y+vel + yellow.height < HEIGHT - 15: #DOWN
        yellow.y += vel

def red_handle_movement(keys_pressed,red):
    if keys_pressed[pygame.K_a] and red.x-vel > BORDER.x+ BORDER.width: #LEFT
        red.x -= vel 
    if keys_pressed[pygame.K_d] and red.x+vel + red.width < WIDTH: #RIGHT
        red.x += vel
    if keys_pressed[pygame.K_w] and red.y - vel > 0: #UP
        red.y -= vel 
    if keys_pressed[pygame.K_s] and red.y+vel + red.height < HEIGHT - 15: #DOWN
        red.y += vel
#############################################################

# Main function
def main():
    red = pygame.Rect(700,300,SPACESHIP_WIDTH,SPACESHIP_HEIGHT)
    yellow = pygame.Rect(100,300,SPACESHIP_WIDTH,SPACESHIP_HEIGHT)

    red_bullets = [] #red player's bullets
    yellow_bullets = [] #yellow player's bullets

    clock = pygame.time.Clock()
    run = True 
    while run:
        clock.tick(FPS)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False
            
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LCTRL:
                    bullet = pygame.Rect(yellow.x+yellow.width,yellow.y+yellow.height/2 - 2,10,5)
                    yellow_bullets.append(bullet)

                if event.key == pygame.K_RCTRL:
                    bullet = pygame.Rect(red.x,red.y+red.height/2 - 2,10,5)
                    red_bullets.append(bullet)


        keys_pressed = pygame.key.get_pressed()
        yellow_handle_movement(keys_pressed,yellow)
        red_handle_movement(keys_pressed, red)
        draw_window(red,yellow)

    pygame.quit()

if __name__ == '__main__':
    main()