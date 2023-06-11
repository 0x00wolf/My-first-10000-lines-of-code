#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get two strings
    // char *variable is the same as variable[]
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    // print dem strings
    printf("%s\n", s);
    printf("%s\n", t);

    //print dere addresses (%p is pointer)
    printf("%p\n", s);
    printf("%p\n", t);
}