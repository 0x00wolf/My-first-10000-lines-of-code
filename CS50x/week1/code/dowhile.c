#include <stdio.h>
#include <cs50.h>

void truth(void);

int main(void)
{
    int repeat;
    do
    {
        repeat = get_int("How many times until it settles in: ");
    }
    while (repeat < 1);
    for (int i = 0; i < repeat; i++)
    {
        truth();
    }
    printf("\n");
}

void truth(void)
{
    printf("A woman's right to choose is her own,\ntime for you to get off the throne.\n");
}
