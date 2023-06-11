#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string names[] = {"Sauron", "Frodo", "Sam", "Bombadil", "Aragorn", "Legolas"};
    for (int i = 0; i < 6; i++)
    {
        if (strcmp(names[i], "Bombadil") == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}