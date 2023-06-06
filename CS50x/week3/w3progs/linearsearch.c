#include <cs50.h>
#include <stdio.h>

int main(void)
{
//array nums
    int numbers[] = {4, 5, 6, 1, 3, 2, 7};

// search for 7
    for (int i = 0; i <= 7; i++)
    {
        if (numbers[i] == 7)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}