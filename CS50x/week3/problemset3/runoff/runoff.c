#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);
void printemvotesguud(void);


////DAS PROGRAM
int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for (int i = 0, j = candidate_count; i < j; i++)
    {
        {
            if (strcmp(candidates[i].name, name) == 0)
            {
                preferences[voter][rank] = i;
                printf("voter: %i, rank: %i, preference: %s\n", (voter + 1), rank, name);
                return true;
            }
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for (int i = 0, j = voter_count; i < j; i++)
    {
        for (int k = 0, l = candidate_count; k < l; k++)
        {
            //hmm think think bud. eat that steak while you're at it
            int cand_x = preferences[i][k];
            if (candidates[cand_x].eliminated == true)
            {
                continue;
            }
            else
            {

                candidates[cand_x].votes += 1;
                break;
            }
        }
    }
//start with preferences[i][0], if candidate 0 is eliminated, preferences[i][j +1]
// if candidates[j].eliminated = false
// candidate[x].votes += 1.
// next voter at this point (break).
// if candidates[j].eliminated = true
// preferences[i][j+1]?
printemvotesguud();
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    for (int k = 0, l = candidate_count; k < l; k++)
    {
        if (candidates[k].votes > (voter_count / 2))
        {
            printf("Winner is: %s\n", candidates[k].name);
            return true;
        }
        else
        {
            continue;
        }
    }
// if candidate has more than half votes
// declare winner (function returns true)
// else exit function and continue with main, function returns false
// if candidate.votes are > than voter count / 2. candidate is the winner
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min_votes = (voter_count);
    for (int k = 0, l = candidate_count; k < l; k++)
    {
        if (candidates[k].eliminated == false)
        {
            if (candidates[k].votes < min_votes)
            {
                min_votes = candidates[k].votes;
                continue;
            }
            else
            {
                continue;
            }
        }
        else
        {
            break;
        }

    }
// loop through remaining candidates (if candidate.eliminated = false)
// if votes does not equal !0 continue
// else name candidate who stops loop as min votes
    return min_votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    bool buddy = false;
    for (int k = 0, l = candidate_count; k < l; k++)
    {
        if (candidates[k].eliminated == false)
        {
            if (candidates[k].votes == min)
            {
                buddy = true;
            }
            else if (candidates[k].votes > min)
            {
                buddy = false;
            }
        }
        else
        {
            continue;
        }
    }
    return buddy;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0, k = candidate_count; i < k; k++)
    {
        if (candidates[i].votes == min && candidates[i].eliminated == false)
        {
            candidates[i].eliminated = true;
            continue;
        }
        else
        {
            continue;
        }
    // if candidate has least votes, bool elimated == true
    // reset candidates[].votes to 0
    }
    return;
}

// more than 50% of votes, candidate is winner
    // if no winner, runoff
    // candidate with fewest votes eliminated.
        // ppl who voted for eliminated candidate now count towards their rank 2 choice

void printemvotesguud(void)
{
    for (int i = 0, j = candidate_count; i < j; i++)
    {
        printf("Candidate: %s, votes: %i\n", candidates[i].name, candidates[i].votes);
    }
}