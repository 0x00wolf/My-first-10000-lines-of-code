#include <stdio.h>
#include <cs50.h>

bool check_phrase(string);
string secret = "freedom";
string secret_2 = "Freedom";

int main(void)
{
    string pwd = get_string("What's the secret password: ");
    check_phrase(pwd);
    if (true)
    {
        printf("The revolution will not be televised.\n");
    }
    else
        printf("Work harder.\n");
}

bool check_phrase(string pwd)
{
    bool outcome;
    if (pwd == secret || pwd == secret_2)
    {
        outcome = true;
    }
    else
    {
        outcome = false;
    }
    return outcome;
}