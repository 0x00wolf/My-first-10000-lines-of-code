#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Get two strings
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    //compare their addresses
    if (s == t)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}
// Results in Different because the locations are seperate in memory regardless if the char inputs are the same