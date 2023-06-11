#include <stdio.h>
void main() {
    char c;
    char last_c;
    while ((c = getchar()) != EOF)
    {
        if (c != ' ' || last_c != ' ')
        {
            putchar(c);
        }
        last_c = c; /* because it sets the character to the
                       previous character every loop */
    }
}