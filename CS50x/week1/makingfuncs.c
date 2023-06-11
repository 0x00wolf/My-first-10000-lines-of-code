#include <stdio.h>
#include <cs50.h>

void howl(void)
{
    printf("Howl at the moon.\n");
}

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        howl();
    }
}