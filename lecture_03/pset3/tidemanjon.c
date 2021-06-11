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

void print_pairs(void);
int get_val(pair p);
void print_pair(pair p);
void arr1d(bool arr[], int len);
bool isin(string elem, string arr[], int size);
int get_index(string elem, string arr[], int size);


int main(int argc, string argv[])
{

    // Beginning for testing
    candidate_count = 3;
    candidates[0] = "Alice";
    candidates[1] = "Bob";
    candidates[2] = "Charlie";
    int voter_count = 9;
    int zvoter_count = 4;
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
//    string votearray[4][3] = {
//        {"Alice", "Charlie", "Bob"},
//        {"Alice", "Charlie", "Bob"},
//        {"Charlie", "Alice", "Bob"},
//        {"Bob", "Alice", "Charlie"}};

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

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);
    } 

//    preferences[2][1] = 9;

    add_pairs();

//    print_pairs();

    sort_pairs();

//    print_pairs();
//    for (int i = 0; i < candidate_count; i++)
//    {
//        arr1d(locked[i], 3);
//    }
//
    lock_pairs();
//
//    for (int i = 0; i < candidate_count; i++)
//    {
//        arr1d(locked[i], 3);
//    }
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
    for (int i = 0; i < candidate_count - 1; i++)
    {   
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }

}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // Loop through preferences and add
    for (int c1 = 0; c1 < candidate_count - 1; c1++)
    {
        for (int c2 = c1 + 1; c2 < candidate_count; c2++)
        {
            int c1overc2 = preferences[c1][c2];
            int c2overc1 = preferences[c2][c1];

            if (c1overc2 > c2overc1)
            {
                pairs[pair_count].winner = c1;
                pairs[pair_count].loser = c2;
//                print_pair(pairs[pair_count]);
                pair_count++;
            }
            else if (c1overc2 < c2overc1)
            {
                pairs[pair_count].winner = c2;
                pairs[pair_count].loser = c1;
//                print_pair(pairs[pair_count]);
                pair_count++;
            }
        }
    }
}


// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int min_index;
    pair temp;
    for (int i = 0; i < pair_count; i++)
    {
        min_index = i; 

        for (int j = i + 1; j < pair_count; j++)
        {
            if (get_val(pairs[j]) > get_val(pairs[min_index]))
            {
                min_index = j;
            }
        temp = pairs[min_index];
        pairs[min_index] = pairs[i];
        pairs[i] = temp;
//        printf("sort_pairs: swaping %i with %i\n", i, min_index);
        }
    }
}



// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    int w, l;
    for (int i = 0; i < pair_count; i++)
    {
        bool loop = false;  // Flag for existing loop
        w = pairs[i].winner;
        l = pairs[i].loser;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[i][j])
            {
                loop = true;
            }
        }
        
        if (!loop)
        {
            locked[w][l] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    for (int c = 0; c < candidate_count; c++)
    {
        bool flag = false;
        for (int r = 0; r < candidate_count; r++)
        {
            if (locked[r][c])
            {
                flag = true;
            }
        }
        if (!flag)
        {
            printf("%s\n", candidates[c]);
        }
    }
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

void arr1d(bool arr[], int len)
{
    printf("[%i", arr[0]);
    for (int i = 1; i < len; i++)
    {
        printf(", %i", arr[i]);
    }
    printf("]\n");
}

void print_pair(pair p)
{
    printf("{winner: %i, loser: %i}", p.winner, p.loser);
}

int get_val(pair p)
{   
//    printf("For pair");
//    print_pair(p);
    int val;
    val = preferences[p.winner][p.loser];
//    printf("\tget_val returns: %i\n", val);
    return val;
}

void print_pairs(void)
{
    printf("[");
    for (int i = 0; i < pair_count; i++)
    {
        print_pair(pairs[i]);
        printf("\tvalue: %i\n", get_val(pairs[i]));
    }
    printf("]\n");
}
