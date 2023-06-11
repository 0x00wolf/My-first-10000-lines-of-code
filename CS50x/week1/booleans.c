#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //prompt for pick a number
    int number = get_int("Pick a number from 1 to 3: ");
    if (number == 1)
    {
        printf("%i is the loneliest number\nthat you'll ever know\n", number);
    }
    else if (number == 2)
    {
        printf("%i halves to a whole\n", number);
    }
    else if (number == 3)
    {
        printf("%i blind mice, see how they run (into walls)\n", number);
    }
    else
    {
        printf("Cheater, eh.\n");
    }
}