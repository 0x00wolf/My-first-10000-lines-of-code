//  1) get the key from the command line when intializing
        // can only allow one argument in
        //argv is an array of strings
        //argv[] must only take 1 argument
            //then convert to a key
            //loop through the command line argument
            //argv 1 is the string 3, must convert it to an int
                //use stdlib.h a2i()
            //isalpha('A'), isupper,
//  2) Get the plaintext in a function
// cna do math to characters A + 1 = 66 if printed as an int
// use modulo 26 to wrap around

//looop through the string of plaintext with strlen

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

//takes in arguments from the command line
//cipher text, plain text, and key
//takes in a string and uses a loop to edit the string by adjusting the ascii value of the integers of each character
// USE variable P for the plain text, K for the key, and c for the ciphertext


//function headers
string get_plaintext(void);
bool only_digits(string key);
void nope(void);

//Need to loop through chars in array[string] (the input
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        // Convert argv[1] from a `string` to an `int`
        bool yes_no = only_digits(argv[1]);
        if (yes_no == true)
        {
        string p = get_plaintext();
        }
        else
        {
            nope();
        }
        // For each character in the plaintext:
            // Rotate the character if it's a letter
        //Then encrypt plaintext and print out :"Ciphertext: " + text on same line

    }
    else
    {
        nope();
    }
}


//key is supplied as argv[1] on the command line, and rotates the input words ascii characters forward by the number of ints in the key

// Function to get text from user print it out and encrypt it.
string get_plaintext(void)
{
    // Make sure every character in argv[1] is a digit
    string plaintext = get_string("plaintext: ");
    printf("%s\n", plaintext);
    return plaintext;
}

//equation:    c = (p + k) % 26
//int get_key(argv[1])
//{
//
bool only_digits(string key)
{

    atoi(key);
    printf("keyiz %i", key);

}
// move forward letters by K positions.
// C = (P + K) % 26

void nope(void)
{
    printf("Usage ./caesar key\n");
    return 1;
}

string encipher(string text)
{
    text[]
}