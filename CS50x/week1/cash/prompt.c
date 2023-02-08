#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int change = 90 % 25;
    return change;
    printf(change);
}
//cents is input and the modulo operator is used
//cents should have the remainder then substracted
//cents post the remainder substracted divided by 3 is the number of quarters