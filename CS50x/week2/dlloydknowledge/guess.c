#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int guess;
    int number = 5;
    do
    {
        guess = get_int("What's your guess? (1-9) ");
        if (guess == number)
        {
            continue;
        }
        else
        {
            printf("Stick around! (throws knife into chest)\n");
        }
    }
    while (guess != number);
    printf("Hasta la vista baby!\n");
}