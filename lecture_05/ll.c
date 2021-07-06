/* JonRdA attempt at creating a linked list

The node struct is defined and a list of one node created.
Then appending, printing and head functions are added operating with the
number and pointer that compose each node.

Adding an element as first does not modify the list pointer because a copy
is passed. However the inner list is correct, as pirnted.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

// Function declarations
void append_list(node *list, int num);
void print_list(node *list);
void head_list(node *list, int num);

int main(void)
{
    // Create empty pointer
    node *list = NULL;

    // First node
    node *n = malloc(sizeof(node));
    if (n != NULL)
    {
        n->number = 7;
        n->next = NULL;
    }

    // Point list to the first node
    list = n;

    // Print the linked list
    print_list(list);
    append_list(list, 9);
    append_list(list, 12);
    head_list(list, 6);
    print_list(list);
}

// Add new node at end of linked list.
void append_list(node *list, int num)
{
    node *n = malloc(sizeof(node));
    if (n != NULL)
    {
        n->number = num;
        n->next = NULL;
    }

    // Find last element of list, take its null pointer and point to n
    node *tmp = list;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    // Now tmp points to last node of list, point its next to new node
    tmp->next = n;
}

/* Add new node at beginning of linked list.
The linked list is correctly modified, a node is added in first position.
However, the list pointer (passed as argument, copy) is not updated.
*/
void head_list(node *list, int num)
{
    node *n = malloc(sizeof(node));
    if (n != NULL)
    {
        n->number = num;
        n->next = list;
    }
    list = n;
    printf("This is inner list: ");
    print_list(list);
    
}

// Print linked list by following pointers and printing the number.
void print_list(node *list)
{
    node *tmp = list;
    printf("[");
    while (tmp->next != NULL)
    {
        printf("%i, ", tmp->number);
        tmp = tmp->next;
    }
    printf("%i]\n", tmp->number);
}

