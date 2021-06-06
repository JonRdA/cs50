#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

bool isin(string elem, string arr[], int size);
int get_index(string elem, string arr[], int size);


int main(int argc, string argv[])
{

    // Beginning for testing
    candidate_count = 3;
    candidates[0] = "Alice";
    candidates[1] = "Charlie";
    candidates[2] = "Bob";
    int voter_count = 9;
    string votearray[9][3] = {
        {"Alice", "Bob", "Charlie"},
        {"Alice", "Bob", "Charlie"},
        {"Alice", "Bob", "Charlie"},
        {"Bob", "Charlie", "Alice"},
        {"Bob", "Charlie", "Alice"},
        {"Charlie", "Alice", "Bob"},
        {"Charlie", "Alice", "Bob"},
        {"Charlie", "Alice", "Bob"},
        {"Charlie", "Alice", "Bob"}};


    // // Check for invalid usage
    // if (argc < 2)
    // {
    //     printf("Usage: tideman [candidate ...]\n");
    //     return 1;
    // }

    // // Populate array of candidates
    // candidate_count = argc - 1;
    // if (candidate_count > MAX)
    // {
    //     printf("Maximum number of candidates is %i\n", MAX);
    //     return 2;
    // }
    // for (int i = 0; i < candidate_count; i++)
    // {
    //     candidates[i] = argv[i + 1];
    // }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    // int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            // string name = get_string("Rank %i: ", j + 1);
            string name = votearray[i][j];
            // printf("%s\n", name);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // printf("%s", candidates[1]);
    if (isin(name, candidates, candidate_count) == 1)
    {
        int index = get_index(name, candidates, candidate_count);
        ranks[rank] = index;
        return true;
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}


// Jon helper functions
bool isin(string elem, string arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(elem, arr[i]) == 0)
        {
            return true;
        }
    }
    return false;
}


int get_index(string elem, string arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i], elem) == 0)
        {
            return i;
        }
    }
    return false;
}

