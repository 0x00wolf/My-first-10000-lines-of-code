#include <stdio.h>

void main()
{
    printf("Hello, world!\n");
    puts("Hello, ");
    puts("world!");
    printf("Hello, ");
    printf("world!");
    printf("\n");
    for (int x = 0; x < 9; x++)
    {
        printf("\\\\\\\"");
        printf("\\\\\\\"");
        printf("\\\\\\\n");
    }
}