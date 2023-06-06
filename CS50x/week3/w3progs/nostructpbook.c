#include <cs50.h>
#include <stdio.h>
#include <string.h>
//assumes that the number and the person are in the same position in their respective arrays

int main(void)
{
    string names[] = {"Kayla", "Alec", "Bafana", "Mischa"};
    string numbers[] = {"902-1", "902-2", "902-3", "902-4"};

    for (int i = 0; i < 4; i++)
    {
        if (strcmp(names[i], "Bafana") == 0)
        {
            printf("Found %s %s\n", names[i], numbers[i]);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}