#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// func. defs.
bool isalphabetical(string input);
bool is26chars(string input);
int endersgame(void);
string userinput(void);
void willenium(string key, string input);

//PROG ROCK.
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("one small step for man\n");
        if (strlen(argv[1]) != 26)
        {
            endersgame();
        }
        else if (strlen(argv[1]) == 26)
        {
            //function is broken
            bool ccc = is26chars(argv[1]);
            if (ccc == true)
            {
                printf("Big boss rabbit, on some boss shit\n");
                string key = argv[1];
                bool bbb = isalphabetical(key);
                if (bbb == true)
                {
                    printf("Slam, on some boss shit\n");

                }
                else
                {
                    endersgame();
                }
            }
            else
            {
                endersgame();
            }
        }
    }
    else
    {
        endersgame();
    }
    return 0;
}


//  Check if input is only alphabetical chars
bool isalphabetical(string input)
{
    bool alpha = false;
    for (int xx = 0, yy = strlen(input); xx < yy; xx++)
    {
        char testing = input[xx];
        if (isalpha(testing))
        {
            alpha = true;
        }
        else
        {
            endersgame();
        }
    }
    return alpha;
}

//  check if input is only 26 chars
bool is26chars(string input)
{
    int x = 26;
    if (strlen(input) == x)
    {
        return true;
    }
    else
    {
        endersgame();
    }
    return true;
}

//  Kill the program and scold the user.
int endersgame(void)
{
    printf("*BREAKDOWN: Key must be 26 alphabetical chars.\n");
    exit(1);
}

//  Get the user input.
string userinput(void)
{
        string plaintext = get_string("plaintext:  ");
        printf("%s\n", plaintext);
        return plaintext;
}

//  Willenium: loop through plaintext replacing alphabetical chars with the key equivalent (party like it's 1999).
void willenium(string key, string input)
{
//for (int cc = 0, bb = strlen(plaintext); cc <= bb; cc ++)
//{
//    char encryptme = plaintext[cc];
//}
}
