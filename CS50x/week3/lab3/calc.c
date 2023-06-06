#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float a = get_float("usr time: ");
    float b = get_float("sys time: ");
    printf("Running time: %f\n", (a + b));
}