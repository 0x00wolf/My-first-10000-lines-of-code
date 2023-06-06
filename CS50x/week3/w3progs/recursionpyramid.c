#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    //height is
    int height = get_int("Height: ");
    //draw da pyramid
    draw(height);
}

void draw(int n)
{
    //if nothing to draw. chill.
    if (n <= 0)
    {
        return;
    }
    //draw pyramid of a height of n-1;
    draw(n - 1);

    //draw one more row of width n
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}