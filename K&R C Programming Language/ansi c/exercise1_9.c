#include <stdio.h>
void main() {
    char c, pc;
    pc = EOF;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ') {
            if (pc != ' ')
                putchar(c);
        }
        else if(c != ' ')
            putchar(c);
        pc = c;
    }
}