#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

//Functions created:
string get_text(void);
int count_letters(string body);
int count_words(string body);
int count_sentences(string body);
int letter_count, sentence_count, word_count;

//Das Program
int main(void)
{
    string passage = get_text();
    int letterz = count_letters(passage);
    float wordz = count_words(passage);
    int sentencez = count_sentences(passage);
    float coleman_l = (float) letterz / wordz * 100;
    float coleman_s = sentencez / wordz * 100;
    int index = round((0.0588) * (coleman_l) - (0.296 * coleman_s) - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index <= 16)
    {
        printf("Grade %i\n", index);
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("NEIN\n");
    }
}
//works until:

//Function to get the words to input from the user
string get_text(void)
{
    string textinput = get_string("Text: ");
    printf("%s\n", textinput);
    return textinput;
}

//Function to count the number of letters input
int count_letters(string body)
{
    for (int i = 0, j = strlen(body); i <= j; i++)
    {
        if (isalpha(body[i]))
        {
            letter_count += 1;
        }
        else
        {
            continue;
        }
    }
    printf("Letters: %i\n", letter_count);
    return letter_count;
}

//Count the number of words
int count_words(string body)
{
    for (int i = 0, j = (strlen(body)); i <= j; i++)
    {
        if (isspace(body[i]))
        {
            word_count += 1;
        }
        else
        {
            continue;
        }
    }
    word_count += 1;
    printf("Words: %i\n", word_count);
    return word_count;
}

//Count the number of sentences
int count_sentences(string body)
{
    for (int i = 0, j = (strlen(body)); i <= j; i++)
    {
        if (body[i] == (int) 46 || body[i] == (int) 33 || body[i] == (int) 63)
        {
            sentence_count += 1;
        }
        else
        {
            continue;
        }
    }
    printf("Sentences: %i\n", sentence_count);
    return sentence_count;
}

// L = the average number of letters per 100 words
    // To determine L -> (letters / sentences) * 100 = X
// S = the average number of sentences per 100 words
        // To determine S -> (sentences / words) * 100 = Y


//Compute the index
        //index = rounded((0.0588 * L) - (0.296 * S) - 15.8))
