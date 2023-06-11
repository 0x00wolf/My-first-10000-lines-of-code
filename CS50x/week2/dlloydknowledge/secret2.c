#include <stdio.h>
#include <string.h>
#include <cs50.h>

bool check_phrase(string);

int main(void)
{
    string word_is = get_string("What's the secret password: ");
    bool correct = check_phrase(word_is);
    if (correct == true)
    {
        printf("The revolution will not be televised.\n");
    }
    else
        printf("Work harder.\n");
}

bool check_phrase(string a)
{
    string secret = "freedom";
    string secret_2 = "Freedom";

    if (strcmp(a, secret) == 0)
    {
        return true;
    }
    else if (strcmp(a, secret_2) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}