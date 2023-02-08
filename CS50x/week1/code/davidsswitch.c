#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x = get_int("Pick a number from 1-3: ");
    switch(x)
    {
        case 1:
            printf("One!\n");
            break;
        case 2:
            printf("Two!\n");
            break;
        case 3:
            printf("Three!\n");
            break;
        default:
            printf("Y tu mama tambien!!!\ncd ");
            break;
    }
}
