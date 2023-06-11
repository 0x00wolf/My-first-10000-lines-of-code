#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

// initalize variables for x, and y coords for snake + cash
int headX, headY, cashX, cashY;
// create game board space
int width = 30, height = 30;
int bodyX[1000], bodyY[1000];

int gameOver = 0;
int direction = 2;
int speeds = 0.8i;
int length = 0;
int score = 0;
int speed = 60000;

// main game functions
void render(void);
void setupGame(void);
void checkInput(void);
void moveSnake(void);
void checkGameOver(void);
void spawnCash(void);
void checkCash(void);

// Re-implementing functions from conio.h - an old dos library 
int kbhit(void);
char getch(void);

void main() {
    setupGame();
    spawnCash();

    while(!gameOver) {
        render();
        checkInput();
        moveSnake();
        checkCash();
        checkGameOver();
        usleep(speed);
    }
    usleep(speed);
    system("clear");
    printf("\n\n\n\t\tFINAL SCORE : %5d\n\n\t\tNOKIA BRICK FOREVER!!!\n\t\t(press any + enter to exit)\n\t\t\t>>", score);
    scanf(">>");
    system("clear");
}

// render game in terminal
void render(void) {
    system("clear");
    int i, j, k, p;
    // iterate through all the y coords
    for (j = 0; j <= height; j++) {
        // iterate through all the  x coords
        for (i = 0; i <= width; i++) {
            p = 1;
            // generate the border
            if (i == 0 || j == 0 || j == height || i == width) {
                printf("X");
            }
            // print a '$ if the x+y coords match the location of the spawned cash
            else if (i == cashX && j == cashY) {
                printf("$");
            }
            // print a directional arrow if the x+y coords match the snake's head
            else if (i == headX && j == headY) {
                if (direction == 1) {
                    printf("^");
                }
                else if (direction == 2) {
                    printf(">");
                }
                else if (direction == 3) {
                    printf("v");
                }
                else if (direction == 4) {
                    printf("<");
                }
                // add code here to change the snakes head to a directionally appropriate arrow.
            }
            else {
                for (k = 0; k < length; k++) {
                    if (i == bodyX[k] && j == bodyY[k]) {
                        printf("x");
                        p = 0;
                    }
                }
                if (p) {
                printf(" ");           
                }
            }
        }
        printf("\n");
    }
    printf("Score: %5d", score);
}

void spawnCash(void) {
    spawnCashX : cashX = rand() % 20;
    if (cashX <= 2 || cashX >= width - 2) {
        goto spawnCashX;
    }
    spawnCashY : cashY = rand() % 20;
    if (cashY <= 2 || cashX >= width - 2) {
        goto spawnCashY;
    }
}

void setupGame(void) {
    headX = height / 2;
    headY = width / 2;
}

void checkCash(void) {
    if (headX == cashX && headY == cashY) {
        score += 10;
        length++;
        speed -= 1000;
        spawnCash();
    }
}

void checkInput(void) {
    if (kbhit()) {
        char key = getch();
        switch (key) {
            case 'w':
                if (direction != 3)
                    direction = 1;
                break;
            case 'd':
                if (direction != 4)
                    direction = 2;
                break;
            case 's':
                if (direction != 1)
                    direction = 3;
                break;
            case 'a':
                if (direction != 2)
                    direction = 4;
        }
    }
}

void moveSnake(void) {
    int x1, x2, y1, y2, i;

    if (length == 1) {
        bodyX[0] = headX;
        bodyY[0] = headY;
    }
    else {
        x1 = headX;
        y1 = headY;

        for (i = 0; i < length; i++) {
            x2 = bodyX[i];
            y2 = bodyY[i];
            bodyX[i] = x1;
            bodyY[i] = y1;
            x1 = x2;
            y1 = y2;
        }
    }
    switch (direction) {
        case 1:
            headY--;
            break;
        case 2:
            headX++;
            break;
        case 3:
            headY++;
            break;
        case 4:
            headX--;
    }
}

void checkGameOver(void) {
    int i;
    
    for (i = 0; i < length; i++) {
        // check if the head has collided with the body
        if (headX == bodyX[i] && headY == bodyY[i]) {
            gameOver = 1;
        }
        // check if the head has collided with the border
        if (headX == width || headX == 0 || headY == height || headY == 0) {
            gameOver = 1;
        }
    }
}

// original repository for the following: https://github.com/zoelabbb/conio.h/blob/master/conio.h
// conio.h function to determine if a keyboard key was pressed.
int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf| O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

char getch(void) {
    char c;

    system("stty raw");
    c = getchar();
    system("stty sane");
    
    return(c);
}

// Code forked from: https://github.com/t0uh33d/C_programs/blob/main/snake_game_terminal_linux/snake_game.c
