#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //prompt for x & y
    int x = get_int("X: ");
    int y = get_int("Y: ");
    //perform addition
    printf("%i\n", x+y);
}