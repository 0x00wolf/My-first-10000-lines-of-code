#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// func. defs.
bool isalphabetical(string input);
bool is26chars(string input);
string userinput(void);
void encryptbb(string key, string input);
char rotate(char cuz, string key);

//PROG ROCK.
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        return 1;
    }
    else
    {
        bool ccc = is26chars(argv[1]);
        if (ccc == true)
        {
            string key = argv[1];
            for (int m = 0, n = strlen(key); m < n; m++)
            {
                if (isalpha(key[m]))
                {
                    continue;
                }
                else
                {
                printf("*BREAKDOWN: Key must be 26 alphabetical chars.\n");
                return 1;
                }
            }
            string secrets = userinput();
            encryptbb(key, secrets);
            printf("\n");
            return 0;
        }
        else
        {
            printf("*BREAKDOWN: Key must be 26 alphabetical chars.\n");
            return 1;
        }
    }
    return 0;
}


//  check if input is only 26 chars
bool is26chars(string input)
{
    bool bubba = false;
    int x = 26;
    if (strlen(input) == x)
    {
        bubba = true;
    }
    else
    {
        bubba = false;
    }
    return bubba;
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
                char secreted = rotate(xx, key);
                printf("%c", toupper(secreted));
            }
            else if (islower(xx))
            {
                char lsecreted = rotate(xx, key);
                printf("%c", tolower(lsecreted));
            }
        }
        else
        {
            printf("%c", xx);
        }
    }
    printf("\n");
}

//rotate with the key
char rotate(char cuz, string key)
{
    if (cuz == 'a' || cuz == 'A')
    {
        cuz = key[0];
        return cuz;
    }
    else if (cuz == 'b' || cuz == 'B')
    {
        cuz = key[1];
        return cuz;
    }
    else if (cuz == 'c' || cuz == 'C')
    {
        cuz = key[2];
        return cuz;
    }
    else if (cuz == 'd' || cuz == 'D')
    {
        cuz = key[3];
        return cuz;
    }
    else if (cuz == 'e' || cuz == 'E')
    {
        cuz = key[4];
        return cuz;
    }
    else if (cuz == 'f' || cuz == 'F')
    {
        cuz = key[5];
        return cuz;
    }
    else if (cuz == 'g' || cuz == 'G')
    {
        cuz = key[6];
        return cuz;
    }
    else if (cuz == 'h' || cuz == 'H')
    {
        cuz = key[7];
        return cuz;
    }
    else if (cuz == 'i' || cuz == 'I')
    {
        cuz = key[8];
        return cuz;
    }
    else if (cuz == 'j' || cuz == 'J')
    {
        cuz = key[9];
        return cuz;
    }
    else if (cuz == 'k' || cuz == 'K')
    {
        cuz = key[10];
        return cuz;
    }
    else if (cuz == 'l' || cuz == 'L')
    {
        cuz = key[11];
        return cuz;
    }
    else if (cuz == 'm' || cuz == 'M')
    {
        cuz = key[12];
        return cuz;
    }
    else if (cuz == 'n' || cuz == 'N')
    {
        cuz = key[13];
        return cuz;
    }
    else if (cuz == 'o' || cuz == 'O')
    {
        cuz = key[14];
        return cuz;
    }
    else if (cuz == 'p' || cuz == 'P')
    {
        cuz = key[15];
        return cuz;
    }
    else if (cuz == 'q' || cuz == 'Q')
    {
        cuz = key[16];
        return cuz;
    }
    else if (cuz == 'r' || cuz == 'R')
    {
        cuz = key[17];
        return cuz;
    }
    else if (cuz == 's' || cuz == 'S')
    {
        cuz = key[18];
        return cuz;
    }
    else if (cuz == 't' || cuz == 'T')
    {
        cuz = key[19];
        return cuz;
    }
    else if (cuz == 'u' || cuz == 'U')
    {
        cuz = key[20];
        return cuz;
    }
    else if (cuz == 'v' || cuz == 'V')
    {
        cuz = key[21];
        return cuz;
    }
    else if (cuz == 'w' || cuz == 'W')
    {
        cuz = key[22];
        return cuz;
    }
    else if (cuz == 'x' || cuz == 'X')
    {
        cuz = key[23];
        return cuz;
    }
    else if (cuz == 'y' || cuz == 'Y')
    {
        cuz = key[24];
        return cuz;
    }
    else if (cuz == 'z' || cuz == 'Z')
    {
        cuz = key[25];
        return cuz;
    }
    return cuz;
}