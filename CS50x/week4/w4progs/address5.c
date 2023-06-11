#include <stdio.h>

int main(void)
{
// Prints address of first char in a string
    char *s = "HI!";
    char c = s[0];
    char *p = &c;
    printf("%p\n", p);
}