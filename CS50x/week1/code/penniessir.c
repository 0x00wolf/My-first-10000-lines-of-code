#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float numbucks = get_float("Dollar amount: ");
    int pennies = numbucks * 100;
    printf("Pennies: %i\n", pennies);
}