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
void encryptbb(string key, string input);
char rotate(char cuz, string key);

//PROG ROCK.
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        bool ccc = is26chars(argv[1]);
        if (ccc == true)
        {
            string key = argv[1];
            bool bbb = isalphabetical(key);
            if (bbb == true)
            {
                string secrets = userinput();
                encryptbb(key, secrets);
                printf("\n");
                return 0;
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
    else
    {
        endersgame();
    }
    return 0;
}


//  Check if key is only alphabetical chars
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
        return plaintext;
}

//  Willenium: loop through plaintext replacing alphabetical chars with the key equivalent (party like it's 1999).
void encryptbb(string key, string input)
{
    printf("ciphertext: ");
    for (int cc = 0, bb = strlen(input); cc < bb; cc++)
    {
        char xx = input[cc];
        if (isalpha(xx))
        {
            if (isupper(xx))
            {
                char encryptme = tolower(xx);
                char secreted = rotate(encryptme, key);
                printf("%c", toupper(secreted));
            }
            else if (islower(xx))
            {
                char lsecreted = rotate(xx, key);
                printf("%c", lsecreted);
            }
        }
        else
        {
            printf("%c", xx);
        }
    }
}

//for (int cc = 0, bb = strlen(plaintext); cc <= bb; cc ++)
//{
//    char encryptme = plaintext[cc];
//}


char rotate(char cuz, string key)
{
    if (cuz == 'a')
    {
        cuz = key[0];
        return cuz;
    }
    else if (cuz == 'b')
    {
        cuz = key[1];
        return cuz;
    }
    else if (cuz == 'c')
    {
        cuz = key[2];
        return cuz;
    }
    else if (cuz == 'd')
    {
        cuz = key[3];
        return cuz;
    }
    else if (cuz == 'e')
    {
        cuz = key[4];
        return cuz;
    }
    else if (cuz == 'f')
    {
        cuz = key[5];
        return cuz;
    }
    else if (cuz == 'g')
    {
        cuz = key[6];
        return cuz;
    }
    else if (cuz == 'h')
    {
        cuz = key[7];
        return cuz;
    }
    else if (cuz == 'i')
    {
        cuz = key[8];
        return cuz;
    }
    else if (cuz == 'j')
    {
        cuz = key[9];
        return cuz;
    }
    else if (cuz == 'k')
    {
        cuz = key[10];
        return cuz;
    }
    else if (cuz == 'l')
    {
        cuz = key[11];
        return cuz;
    }
    else if (cuz == 'm')
    {
        cuz = key[12];
        return cuz;
    }
    else if (cuz == 'n')
    {
        cuz = key[13];
        return cuz;
    }
    else if (cuz == 'o')
    {
        cuz = key[14];
        return cuz;
    }
    else if (cuz == 'p')
    {
        cuz = key[15];
        return cuz;
    }
    else if (cuz == 'q')
    {
        cuz = key[16];
        return cuz;
    }
    else if (cuz == 'r')
    {
        cuz = key[17];
        return cuz;
    }
    else if (cuz == 's')
    {
        cuz = key[18];
        return cuz;
    }
    else if (cuz == 't')
    {
        cuz = key[19];
        return cuz;
    }
    else if (cuz == 'u')
    {
        cuz = key[20];
        return cuz;
    }
    else if (cuz == 'v')
    {
        cuz = key[21];
        return cuz;
    }
    else if (cuz == 'w')
    {
        cuz = key[22];
        return cuz;
    }
    else if (cuz == 'x')
    {
        cuz = key[23];
        return cuz;
    }
    else if (cuz == 'y')
    {
        cuz = key[24];
        return cuz;
    }
    else if (cuz == 'z')
    {
        cuz = key[25];
        return cuz;
    }
    return cuz;
}