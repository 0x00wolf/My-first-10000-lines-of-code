#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //get that integer. comments 4 comments sake
    int n = get_int("pick a number 1-100: ");
    if (n > 0 && n < 101)
    {
        if (n % 2 == 0)
        {
            printf("That is an even #\n");
        }
        else
        {
            printf("That is an odd #\n");
        }
    }
    else
    {
        printf("Cheater!!!\n");
    }
}