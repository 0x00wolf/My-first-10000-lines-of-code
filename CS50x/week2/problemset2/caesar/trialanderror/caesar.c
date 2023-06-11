#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


//function definitions
bool only_digits(string s);
string get_input(void);
void pirate(char huck, int key);


//MAIN prog
    //  1) only allow 2 for the argument count or print "Usage ./caesar key"
    //  2) confirm that argv[1] is only numbers (0-9) for each character in the string
    //      2b) If false, print "Usage ./caesar key"
    //  3) If true, Use the formula to convert the chars int value in argv[1] by the key to ciphertext
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        bool zombie = only_digits(argv[1]);
        if (zombie == true)
        {
            string imp = get_input();
            printf("ciperhtext: ");
            int key = atoi(argv[1]);
    //  3a) das formula:
        //c[i] = (p[i] + k)%26
        // p = plaintext, i refers to a character in p
        // c = ciphertext, i refers to a character in c
        // k = the secret key
        // modulo 26 is because an int could become a different number ->
            //as we use ascii to transform from p to c with the key
        //  try this: use a while string != '\0' to loop through
        //and printf the int of the char with das formula performed on them
            for (int cc = 0, bb = strlen(imp); cc < bb; cc++)
            {
                if (isalpha(imp[cc]))
                {
                    pirate(imp[cc], key);
                }
                else
                {
                    printf("%c", imp[cc]);
                }
            }
            printf("\n");
        }
    }
    else
    {
        printf("Usage ./caesar key\n");
        return 0;
    }
}


//function to determine if boolean is only digits
bool only_digits(string s)
{
    for (int x = 0, y = strlen(s); x < y; x++)
    {
        if (isdigit((char) s[x]))
        {
            continue;
        }
        else
        {
            printf("Usage ./caesar key\n");
            return 0;
        }
    }
    return 1;
}


// get that plaintext
string get_input(void)
{
    string pen1 = get_string("plaintext:  ");
    return pen1;
}


void pirate(char huck, int key)
{
    if (huck >= 'a' && huck <= 'z')
        {
            huck = (((int) huck - 97) + key) % 26;
            huck = huck + 97;
            printf("%c", huck);
        }
    else if (huck >= 'A' && huck <= 'Z')
        {
            huck = (((int) huck - 65) + key) % 26;
            huck = huck + 65;
            printf("%c", huck);
        }
}
