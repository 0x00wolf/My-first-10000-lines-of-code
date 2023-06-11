#include <stdio.h>
#include <cs50.h>

//decalre functions
int add_cha_ints(int a, int b);

int main(void)
{
    int x = get_int("Input integer: ");
    int y = get_int("Moar: ");
// add them bad boys with a function call
    int z = add_cha_ints(x, y);
    printf("The sum of %i and %i is %i!\n", x, y, z);
}

int add_cha_ints(a, b)
{
    int sum = a + b;
    return sum;
}