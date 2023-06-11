#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string response = get_string("Input name: ");
    printf("Hello, %s.\nGreetings fellow traveller.\n", response);
}