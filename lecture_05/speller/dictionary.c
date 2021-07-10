// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Loading function declarations
node *init_node(char *w);

// Number of buckets in hash table
const unsigned int N = 1;

// Hash table
node *table[N];

// ===========================================================================
// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    return false;
}

// ===========================================================================
// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    return 0;
}
// ===========================================================================
// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }
    // Needs to be checked for null pointer
    char *w= malloc(sizeof(char) * (LENGTH + 1));
    while (fscanf(dict, "%s", w) != EOF)
    {
        node *n = init_node(w);
        free(w);
        
        printf("Loaded word on node: '%s'\n", n->word);
        w= malloc(sizeof(char) * (LENGTH + 1));
        if (w== NULL)
        {
            return false;
        }
    }

    // TODO
    return false;
}

// Initialize new node with word 'w'
node *init_node(char *w)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        printf("Could not allocate new node\n");
    }
    strcpy(n->word, w);
    n->next = NULL;
    return n;
}

// ===========================================================================
// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// ===========================================================================
// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
