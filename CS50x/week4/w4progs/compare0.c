#include <stdio.h>

int main(void)
{
    // Get two ints
    int i;
    int j;
    printf("i: ");
    scanf("%d", &i);
    printf("j: ");
    scanf("%d", &j);

    // Compare dem ints
    if (i == j)
    {
        printf("Same same\n");
    }
    else
    {
        printf("Differente\n");
    }
    return 0;
}