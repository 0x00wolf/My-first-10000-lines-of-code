#include <stdio.h>
#include <string.h>

int main(void)
{
    int i = 100;
    int hundopchef[i];
    for (int j = 0; j <= i; j++)
    {
        hundopchef[j] = j;
        printf("%i\n", hundopchef[j]);
    }
    printf("I've got %i problems,\nbut an array ain't %i.\n",
            hundopchef[99], hundopchef[1]);