#include <stdio.h>
#include <cs50.h>

void meow(void);
int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        meow();
    }
}

//meow function
void meow(void)
{
    printf("meow\n");
}