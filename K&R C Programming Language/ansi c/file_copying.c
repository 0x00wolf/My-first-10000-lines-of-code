#include<stdio.h>
/* Copy input to output; 1st version */
void main ()
{
    char c;
    
    c = getchar();
    while (c!=EOF) {
        putchar(c);
        c = getchar();
    }
}