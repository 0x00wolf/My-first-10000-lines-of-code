#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);

// Print the chars in the string
    printf("%c\n", s[0]);
    printf("%c\n", s[1]);
    printf("%c\n", s[2]);
    printf("%c DAS NULL\n", s[3]);

// Printing the chars from the string with pointer arithmetic
    printf("%c\n", s[0]);
    printf("%c\n", s[0+1]);
    printf("%c\n", s[0+2]);

// Or
    printf("\n");
    printf("%c\n", *s);
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s +2));

// Printing an array using pointer arithmetic
    int numbers[] = {4, 6, 8, 2, 7, 5, 0};

    printf("%i\n", *numbers);
    printf("%i\n", *(numbers + 1));
    printf("%i\n", *(numbers + 2));
    printf("%i\n", *(numbers + 3));
    printf("%i\n", *(numbers + 4));
    printf("%i\n", *(numbers + 5));
    printf("%i\n", *(numbers + 6));
    printf("Born to be bad.\n");
    }