#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int a = 2;
    unsigned int j = get_int("how many bytes (1-4): ");
    if (j < 4 && j > 0)
    {
        j = j * 8;
        printf("0 or 1\n");
        for (int i = 1; i < j; i++)
        {
            printf("0 or %i\n", a);
            a = a * 2;
        }
    }
    else if (j == 4)
    {
        j = j * 8;
        printf("0 or 1\n");
        for (int i = 2; i < j; i++)
        {
            printf("0 or %i\n", a);
            a = a * 2;
        }
        printf("0 or 2147483648\n");
    }
    else
    {
        printf("Don't break my code,\nmy achey breaky code.\n");
    }
}