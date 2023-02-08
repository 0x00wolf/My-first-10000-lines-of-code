#include <stdio.h>
#include <cs50.h>

int main(void)
    {
    int x = get_int("Seconds until blastoff (1-10): ");
    if (x <= 10 && x > 0)
    {
        switch(x)
        {
            case 10:
                printf("Ten!\n");
            case 9:
                printf("Nine!\n");
            case 8:
                printf("Eight!\n");
            case 7:
                printf("Seven\n");
            case 6:
                printf("Six!\n");
            case 5:
                printf("Five!\n");
            case 4:
                printf("Four!\n");
            case 3:
            printf("Three!\n");
            case 2:
                printf("Two!\n");
            case 1:
                printf("ONE!\n");
            default:
                printf("OPA GANGNAM STYLE\n");
        }
    }
    else
    {
        printf("Psy is not pleased.\n");
    }
}