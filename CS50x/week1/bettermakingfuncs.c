#include <stdio.h>
#include <cs50.h>

void howl(void);

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        howl();
    }
}

void howl(void)
{
    printf("Howl at the sun.\n");
}