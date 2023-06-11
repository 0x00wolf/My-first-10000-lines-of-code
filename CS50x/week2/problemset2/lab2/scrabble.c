#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>


// Points assigned to each letter of the alphabet, Global variable life.
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1,
                1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

//function headers
int compute_score(string word);
void winning(int score_un, int score_deux);

//Da program
int main(void)
{
//Get the words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

//Compute the scores
    int score_1 = compute_score(word1);
    int score_2 = compute_score(word2);

//Print the winner
    winning(score_1, score_2);
}


//Compute that score bud.
int compute_score(string word)
{
    int da_score = 0;
    for (int x = 0, i = strlen(word); x <= i ; x++)
    {
        char computeme = toupper(word[x]);

        if (computeme == (char) 'A')
        {
            da_score += POINTS[0];
        }
        else if (computeme == 'B')
        {
            da_score += POINTS[1];
        }
        else if (computeme == 'C')
        {
            da_score += POINTS[2];
        }
        else if (computeme == 'D')
        {
            da_score += POINTS[3];
        }
        else if (computeme == 'E')
        {
            da_score += POINTS[4];
        }
        else if (computeme == 'F')
        {
            da_score += POINTS[5];
        }
        else if (computeme == 'G')
        {
            da_score += POINTS[6];
        }
        else if (computeme == 'H')
        {
            da_score += POINTS[7];
        }
        else if (computeme == 'I')
        {
            da_score += POINTS[8];
        }
        else if (computeme =='J')
        {
            da_score += POINTS[9];
        }
        else if (computeme =='K')
        {
            da_score += POINTS[10];
        }
        else if (computeme =='L')
        {
            da_score += POINTS[11];
        }
        else if (computeme =='M')
        {
            da_score += POINTS[12];
        }
        else if (computeme =='N')
        {
            da_score += POINTS[13];
        }
        else if (computeme =='O')
        {
            da_score += POINTS[14];
        }
        else if (computeme =='P')
        {
            da_score += POINTS[15];
        }
        else if (computeme =='Q')
        {
            da_score += POINTS[16];
        }
        else if (computeme =='R')
        {
            da_score += POINTS[17];
        }
        else if (computeme =='S')
        {
            da_score += POINTS[18];
        }
        else if (computeme =='T')
        {
            da_score += POINTS[19];
        }
        else if (computeme =='U')
        {
            da_score += POINTS[20];
        }
        else if (computeme =='V')
        {
            da_score += POINTS[21];
        }
        else if (computeme =='W')
        {
            da_score += POINTS[22];
        }
        else if (computeme =='X')
        {
            da_score += POINTS[23];
        }
        else if (computeme =='Y')
        {
            da_score += POINTS[24];
        }
        else if (computeme =='Z')
        {
            da_score += POINTS[25];
        }
        else
        {
            continue;
        }
    }
    return da_score;
}

//Determine & print the winner
void winning(int score_un, int score_deux)
{
    if (score_un > score_deux)
    {
        printf("Player 1 wins!...\n");
    }
    else if (score_un < score_deux)
    {
        printf("Player 2 wins!...\n");
    }
    else if (score_un == score_deux)
    {
        printf("Tie!");
    }
}


