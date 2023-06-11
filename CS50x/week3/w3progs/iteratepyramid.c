#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    // das height is
    int height = get_int("Height: ");
    // Draw dat pyramid
    draw(height);
}

void draw(int n)
{
    //draw dat
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
