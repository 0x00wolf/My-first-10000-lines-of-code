#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char c = get_char("Do you agree? (y or n) ");
    if (c == 'y' || c == 'Y')
    {
        printf("Agreed.\n");
    }
    else if (c == 'N' || c== 'n')
    {
        printf("Not agreed.\n");
    }
}