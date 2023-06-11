#include <stdio.h>
#include <cs50.h>

void validtriangle(int a, int b, int c);

int main(void)
{
    int side_a = get_int("Length of First side of triangle: ");
    int side_b = get_int("Length of Second side of triangle: ");
    int side_c = get_int("Length of Third side of triangle: ");
    if (side_a > 0 && side_b > 0 && side_c > 0)
    {
        validtriangle(side_a, side_b, side_c);
    }
    else
    {
        printf("You cooked up a story\nand dropped us into a meat grinder!!\n");
    }
}

void validtriangle(int a, int b, int c)
{
    if (a + b > c && b + c > a && a + c > b)
    {
        printf("It's a valid triangle\n");
    }
    else
    {
        printf("Jenky bizness\n");
    }
}