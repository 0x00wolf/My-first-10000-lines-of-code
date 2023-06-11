#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("repeat: ");
    }
    while (n < 1);
    //rows
    for (int i = 0; i < n; i++)
    {
        //columns
        for (int j = 0; j < n; j++)
        {
            printf("I make happy robots.");
        }
        //rows and columns before bros
        printf("\n");
    }
}