#include <stdio.h>

int main(void)
{
//  Prints Address of first char of a string
    char *s = "HI!";
    char *p = &s[0];
    printf("%p\n", p);
}