#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Number: ");
    }
    while (n < 1);
    for (int i = 0; i < n; i++)
    {
        printf("Howl\n");
    }
    printf("\n");
}