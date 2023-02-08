#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    while (true)
    {
        n = get_int("say the thing this many times: ");
        if (n > 1)
        {
            break;
        }
    }
    printf("I lied. I'll do the thing as many times as I choose.\n");
}

