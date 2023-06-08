#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <termios.h>
#include <windows.h>
#include <stdbool.h>

// I am in the process of porting this to Linux.

#define SNAKE_ARRAY_SIZE 310
#include <unistd.h>


#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

int length;
int bend_no;
int len;
char key;
void Record();
void load();
int life;
void Delay(long double);
void Move();
void Food();
int Score();
void Print();
void gotoxy(int x, int y);
void GoToXY(int x, int y);
void Bend();
void Border();
void Down();
void Left();
void Up();
void Right();
void ExitGame();
int ScoreOnly();
int kbhit();
char getch();
void clrscr();
void gotoxy(int x, int y)

typedef struct coordinates {
    int x;
    int y;
    int direction;
} coordinate;

coordinate head, bend[500], food, body[30];

int main() {
    char key;

    Print();

    system("cls");

    load();

    length = 5;

    head.x = 25;
    head.y = 20;
    head.direction = RIGHT;

    Border();

    Food();

    life = 3;

    bend[0] = head;

    Move();

    return 0;
}

int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

	if(ch != EOF)
	{
	    ungetc(ch, stdin);
		return 1;
	}

	 return 0;
}

//http://www.experts-exchange.com/Programming/Languages/C/Q_10119844.html - posted by jos
char getch()
{
    char c;
    system("stty raw");
    c= getchar();
	system("stty sane");
		//printf("%c",c);
	return(c);
}

void clrscr()
{
	system("clear");
	return;
}

void Move() {
    int a, i;
  
    do {
        Food();
        fflush(stdin);

        len = 0;

        for (i = 0; i < 30; i++) {
            body[i].x = 0;
            body[i].y = 0;

            if (i == length) {
                break;
            }
        }
        
        Delay(length);

        Border();

        if (head.direction == RIGHT) {
            Right();
        }
        else if (head.direction == LEFT) {
            Left();
        }
        else if (head.direction == DOWN) {
            Down();
        }
        else if (head.direction == UP) {
            Up();
        }
        ExitGame();
    }
    while(!kbhit());

    a = getch();

    if (a == 27) {
        system("cls");

        exit(0);
    }
    key = getch();

    if ((key == RIGHT && head.direction != LEFT && head.direction != RIGHT) || (key == LEFT && head.direction != RIGHT && head.direction != LEFT) || (key == UP && head.direction != DOWN && head.direction != UP) || (key == DOWN && head.direction != UP && head.direction!= DOWN)) {
        bend_no++;
        bend[bend_no] = head;
        head.direction = key;
        if (key == UP) {
            head.y--;
        }
        if (key == DOWN) {
            head.y++;
        }
        if (key == RIGHT) {
            head.x++;
        }
        if (key == LEFT) {
            head.x--;
        }
        Move();
    }
    else if(key == 27) {
        system("cls");
        exit(0);
    }
    else {
        printf("\a");
        Move();
    }
}

void SetCursorPos(int XPos, int YPos)
{
    coordinate Coord;

    Coord.x = XPos;
    Coord.y = YPos;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coord);
}

void gotoxy(int x, int y) {
    coordinate coord;
    coord.x = x;
    coord.y = y;
    SetConsoleCursorPosition((GetStdHandle(STD_OUTPUT_HANDLE)), &coord);
}

void GoToXY(int x, int y) {
    HANDLE a;
    coordinate b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a, b);
}

void load() {
    int row, col, r, c, q;
    gotoxy(36, 14);
    printf("loading...");
    gotoxy(30, 15);
    for (r = 1; r <= 20; r++) {
        for (q = 0; q <= 100000000; q);
            printf("%c", 177);
        }
    getch();
}

void Down() {
    int i;
    for (i = 0; i <= (head.y - bend[bend_no].y) && len < length; i++) {
        GoToXY(head.x, head.y - i);
        if (len == 0) {
            printf("v");
        }
        else {
            printf("*");
        }
        body[len].x = head.x;
        body[len].y = head.y - i;
        len++;
    }
    Bend();
    if (!kbhit()) {
        head.y++;
    }

void Delay(long double k) {
    Score();
    long double i;
    for(i = 0; i <= 100000000; i++);
}

void ExitGame() {
    int i; 
    int check = 0;

    for (i = 4; i < length; i++) {
        if (body[0].x == body[i].x && body[0].y == body[i].y) {
            check++;
        }
        if (i == length || check != 0) {
            break;
        }
    }
    if (head.x <= 10 || head.x >= 70 || head.y <= 10 || head.y >= 30 || check != 0) {
        life--;
        
        if (life >= 0)
        {
            head.x = 25;
            head.y = 20;
            bend_no = 0;
            head.direction = RIGHT;
            Move();
        }
        else {
            system("cls");
            printf("All lives depleted.\n\n~~~***YOU LOSE BUD***~~~\n\nPress any key to quit the game.\n>>");
            Record();
            exit(0);
        }
    }
}

void Food() {
    // if snake eats the food, seed a new random food location
    if (head.x == food.x && head.y == food.y) {
        length++;
        time_t a;
        a = time(0);
        srand(a);

        // set food x pos accounting for boundaries
        food.x = rand() % 70;
        if (food.x <= 10) {
            food.x+= 11;
        }

        // set food y pos accounting for boundaries
        food.y = rand() % 30;
        if (food.y <= 10) {
            food.y += 11;
        }
        
        // iniate first food
        else if (food.x == 0) {
            food.x = rand() % 70;
            if (food.x <= 10) {
                food.x+= 11;
            }
            food.y = rand() % 30;
            if (food.y <= 10) {
                food.y += 11;
            }
        }
    }
}

void Left() {
    int i;
    
    for (i = 0; i <= (bend[bend_no].x - head.x) && len < length; i++) {
        GoToXY((head.x + i), head.y);
        if (len == 0) {
            printf("<");
        }
        else {
            printf("*");
        }
        // move head coordinate tracker; x + i, and y remains the same 
        body[len].x = head.x + i;
        body[len].y = head.y;
        len++;
    }
    Bend();
    // if no keyboard input, head.x --
    if (!kbhit()) {
        head.x--;
    }
}

void Right() {
    int i;
    for (i = 0; i <= (head.x - bend[bend_no].x) && len < length; i++) {
        // author has in quotes //GoToXY((head.x-i),head.y); figure out why
        body[len].x = head.x - i;
        body[len].y = head.y;
        GoToXY(body[len].x, body[len].y);
        if (len == 0) {
            printf(">");
        }
        else {
            printf("*");
        }
        
    }
    Bend();
    if (!kbhit()) {
        head.x++;
    }
}

void Up() {
    int i;
    
    for(i = 0; i <= (bend[bend_no].y - head.y) && len < length; i++) {
        GoToXY(head.x, head.y + i);
        
        if (len == 0) {
            printf("^");
        }
        else {
            printf("*");
        }
        body[len].x = head.x;
        body[len].y = head.y + i;
        len++;
    }

    Bend();
    if (!kbhit()) {
        head.y--;
    }
}

void Bend() {
    int i, j, diff;

    for (i = bend_no; i >= 0 && len < length; i --) {
        if (bend[i].x == bend[i - 1].x) {
            diff = bend[i].y - bend[i-1].y;
            if (diff < 0) {
                for (j = 1; j <= (-diff); j++) {
                    body[len].x = bend[i].x;
                    body[len].y = bend[i].y + j;
                    GoToXY(body[len].x, body[len].y);
                    printf("*");
                    len++;
                    if (len == length) {
                        break;
                    }
                }
            }
            else if (diff > 0) {
                for (j = 1; j <= diff; j++) {
                    body[len].x = bend[i].x;
                    body[len].y = bend[i].y - j;
                    GoToXY(body[len].x, body[len].y);
                    printf("*");
                    len++;
                    if(len == length) {
                        break;
                    }
                }
            }
        else if (bend[i].y == bend[i - 1].y)
        {
            diff = bend[i].x - bend[i -1].x;
            if (diff < 0 ) {
                for (j = 1; j <= (-diff) && len < length; j++) {
                    body[len].x = bend[i].x + j;
                    body[len].y = bend[i].y;
                    GoToXY(body[len].x, body[len].y);
                    printf("*");
                    len++;
                    if(len == length) {
                        break;
                    }
                }
            }
            else if (diff > 0) {
                for (j = 1; j <= diff && len < length; j++) {
                    body[len].x = bend[i].x - j;
                    body[len].y = bend[i].y;
                    GoToXY(body[len].x, body[len].y);
                    printf("*");
                    len++;
                    if (len == length) {
                        break;
                    }
                }
            }
        }
    }
}

void Border() {
    system("cls");
    int i;
    GoToXY(food.x, food.y);
    printf("F");

    for(i = 10; i < 71; i++) {
        GoToXY(i, 10);
        printf("!");
        GoToXY(i, 30);
        printf("!");
    }

    for (i = 10; i < 31; i++) {
        GoToXY(10, i);
        printf("!");
        GoToXY(70, i);
        printf("!");
    }
}

void Print() {
    printf("**NOKIA SNAKE GAME**\n(press any key to continue)\n");
    if(getch() == 27) {
        exit(0);
    }
}

void record() {
    char plname[20], nplname[20], cha, c;
    int i, j, px;
    FILE *info;
    info = fopen("record.txt", "a+");
    getch();
    system("cls");
    printf("Enter your name\n");
    scanf("%[^\n]", plname);

    for (j = 0; plname[j] != '\0'; j++) {

        nplname[0] = toupper(plname[0]);
        if (plname[j - 1] = ' ') {
            nplname[j] = toupper(plname[j - 1]);
            nplname[j - 1] = plname[j - 1];
        }
        else {
            nplname[j] = plname[j];
        }
    }
    nplname[j] '\0';

    fprintf(info, "Player name: %s\n", nplname);

    time_t mytime;
    mytime = time(NULL);
    fprintf(info, "Date: %s", ctime(&mytime));
    fprintf(info, "Score: %d\n", px = ScoreOnly());

    for (i = 0; i <= 50; i++) { 
        fprintf(info, "%c", '_');
    fprintf(info, "\n");
    fclose(info);
    printf("Would you like to view past records? 'y'\n");
    cha = getch();
    system("cls");
    if (cha == 'y') {
        info = fopen("record.txt", "r");
        do {
            putchar(c = getc(info));
        }
        while (c != EOF);
    }
    fclose(info); 
}

int Score() {
    int score;
    GoToXY(20, 8);
    score = length - 5;
    printf("SCORE: %d", (length - 5));
    score = length - 5;
    GoToXY(50, 8);
    printf("Life: %d", life);
    return score;
}

int ScoreOnly() {
    int score = Score();
    system("cls");
    return score;
}
