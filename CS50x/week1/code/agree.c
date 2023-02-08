#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char c = get_char("Do you agree (y or n): ");
    if (c == 'y' || c == 'Y')
    {
        printf("Agreed\n");
    }
    else if (c == 'n' || c == 'N')
    {
        printf("Agree to disagree\n");
    }
    else
    {
        printf("Follow the instructions, pal.\n");
    }
}