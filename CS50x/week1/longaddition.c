#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //prompt for x and y
    long x = get_long("x: ");
    long y = get_long("y: ");
    //do the thing
    printf("%li\n", x + y);
}