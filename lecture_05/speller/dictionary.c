// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

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
void print_list(node *list);
void print_table(node hash_table[]);

// Unloading
void delete_list(node *list);

// Checking
bool find_list(node *list, const char *word);

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Words loaded
unsigned int count = 0;

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO some preprecessing to the words, lowercase etc.
    // Go to hash given element, search linked list for word.
    int ind = hash(word);
    node *elem = table[ind];
    return find_list(elem, word);
}

// Find a word in the linked list ignoring case
bool find_list(node *list, const char *word)
{
    node *tmp = list;
    while (tmp != NULL)
    {
        if (strcasecmp(tmp->word, word) == 0)
        {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int ind = tolower(word[0]);
    return ind - 97;
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Loads dictionary into memory, returning true if successful else false.
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }

    // Iterate over all words of dictionary.
    bool loop = true;       // looper flag
    while (loop)
    {
        char *w = malloc(sizeof(char) * (LENGTH + 1));

        if (w == NULL)
        {
            printf("Could not load word\n");
            return false;
        }

        // Scan word until end of file, when reached looper flag = false
        if (fscanf(dict, "%s", w) != EOF)
        {
            // Save word to a new node & find table index through hash.
            node *n = init_node(w);
            int ind = hash(w);
            node *elem = table[ind];        // Pointer on table at loc ind

            // If already a list there, make 'n' first by pointing to 'elem'.
            if (elem != NULL)
            {
                n->next = elem;
            }
            table[ind] = n;
            count++;
        }
        else
        {
            loop = false;
        }
        free(w);
    }
    fclose(dict);
    //return false;
    return true;
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

// Print a linked list of string elements.
void print_list(node *list)
{
    if (list == NULL)
    {
        printf("[]\n");
    }
    else
    {
        node *tmp = list;
        printf("[");
        while (tmp->next != NULL)
        {
            printf("%s, ", tmp->word);
            tmp = tmp->next;
        }
        printf("%s]\n", tmp->word);
    }
}

// Print the hash table (array) with its elements being string linked lists
void print_table(node hash_table[])
{
    for (int i = 0; i < N; i++)
    {
        print_list(table[i]);
    }
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *elem = table[i];
        if (elem != NULL)
        {
            delete_list(elem);
        }
    }
    return true;
}

// Recursively delete linked list & free each nodes memory.
void delete_list(node *list)
{
    if (list->next == NULL)
    {
        free(list);
    }
    else
    {
        delete_list(list->next);
        free(list);
    }
}
