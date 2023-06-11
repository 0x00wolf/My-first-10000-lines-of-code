#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// func. defs.
bool is26chars(string input);
int endersgame(void);
string userinput(void);
char willenium(string key, char cuz);

//PROG ROCK.
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int ccc = strlen(argv[1]);
        if (ccc == 26)
        {
            string key = argv[1];
            printf("key: %s\n", key);
            //works until
            for (int xx = 0, yy = strlen(key); xx <= yy; xx++)
            {
                char bb = key[xx];
                printf("Slam, on some boss shit\n");
                string imput = userinput();
                if (isalpha(bb))
                {
                    if (isupper(bb))
                    {
                        char aa = tolower(bb);
                        char printme = willenium(key, aa);
                        char cc = toupper(printme);
                        printf("%c", cc);
                    else if (islower(bb))
                        char printme = willenium(key, bb);
                        printf("%c", printme);
                    }
                else
                    printf("%c", bb);
                }
            }
        else
            endersgame();
        }
    }
    else
    {
        endersgame();
    }
}



//  Check if input is only alphabetical chars
bool isalphabetical(string input)
{
    for (int xx = 0, yy = strlen(input); xx <= yy; xx++)
    {
        char testing = input[xx];
        if (isalpha(testing))
        {
            continue;
        }
        else
        {
            endersgame();
        }
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
        printf("%s", plaintext);
        return plaintext;
}

//  Willenium: loop through plaintext replacing alphabetical chars with the key equivalent (party like it's 1999).
//preserve case, if non alphabetical print as is
char willenium(string key, char cuz)
{
    char output ='\0';
    if (isalpha(cuz))
    {
        if (cuz == 'a')
        {
            output = key[0];
            return output;
        }
        else if (cuz == 'b')
        {
            output = key[1];
            return output;
        }
        else if (cuz == 'c')
        {
            output = key[2];
            return output;
        }
        else if (cuz == 'd')
        {
            output = key[3];
            return output;
        }
        else if (cuz == 'e')
        {
            output = key[4];
            return output;
        }
        else if (cuz == 'f')
        {
            output = key[5];
            return output;
        }
        else if (cuz == 'g')
        {
            output = key[6];
            return output;
        }
        else if (cuz == 'h')
        {
            output = key[7];
            return output;
        }
        else if (cuz == 'i')
        {
            output = key[8];
            return output;
        }
        else if (cuz == 'j')
        {
            output = key[9];
            return output;
        }
        else if (cuz == 'k')
        {
            output = key[10];
            return output;
        }
        else if (cuz == 'l')
        {
            output = key[11];
            return output;
        }
        else if (cuz == 'm')
        {
            output = key[12];
            return output;
        }
        else if (cuz == 'n')
        {
            output = key[13];
            return output;
        }
        else if (cuz == 'o')
        {
            output = key[14];
            return output;
        }
        else if (cuz == 'p')
        {
            output = key[15];
            return output;
        }
        else if (cuz == 'q')
        {
            output = key[16];
            return output;
        }
        else if (cuz == 'r')
        {
            output = key[17];
            return output;
        }
        else if (cuz == 's')
        {
            output = key[18];
            return output;
        }
        else if (cuz == 't')
        {
            output = key[19];
            return output;
        }
        else if (cuz == 'u')
        {
            output = key[20];
            return output;
        }
        else if (cuz == 'v')
        {
            output = key[21];
            return output;
        }
        else if (cuz == 'w')
        {
            output = key[22];
            return output;
        }
        else if (cuz == 'x')
        {
            output = key[23];
            return output;
        }
        else if (cuz == 'y')
        {
            output = key[24];
            return output;
        }
        else if (cuz == 'z')
        {
            output = key[25];
            return output;
        }
    }
    return output;
}

//for (int cc = 0, bb = strlen(plaintext); cc <= bb; cc ++)
//{
//    char encryptme = plaintext[cc];
//}
