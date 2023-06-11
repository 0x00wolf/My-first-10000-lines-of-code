#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// stop it

int main(void)
{
    //Get a string
    string s = get_string("s: ");

    //Copy string's address
    string t = s;

    //Capitalize the frist letter in the string
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }
    //Print string twice
    printf("s: %s\n", s);
    printf("t: %s\n", t);
}