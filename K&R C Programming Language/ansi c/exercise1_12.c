#include <stdio.h>

#define IN 1    /* Inside a word. */
#define OUT 0   /* Outside a word. */

/* Count lines, words, and characters in input */
void main()
{
    int c;

    while ((c = getchar()) != EOF) 
    {
        if (c == ' ' || c == '\t')
        {
            printf("\n");
        }
        else 
        {
            putchar(c);
        }
    }
}