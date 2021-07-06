/* Creates linked list with 3 nodes.
Each node has pointer to the next element of the linked list.

list = [2, 4, 8]
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Initialize our linked list
    node *list = NULL;

    // Create first node: allocate mem, fill number and next (pointer)
    node *n = malloc(sizeof(node));
    if (n != NULL)
    {
        //(*n).number = 2;      This is the verbose way
        n->number = 2;
        n->next = NULL;
        list = n;
    }

    // Add second node of the linked list
    node *n = mallod(sizeof(node));
    if (n != NULL)
    {
        //(*n).number = 4;
        n->number = 4
        n->next = NULL;
    }

    // Link first node to second
    node *tmp = list;
    list->next = n;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = n;
    
}
// Linked list struct, verbose because node does not exist until finished
typedef struct node
{
    int number;
    struct node *next;
}
node;   // alias of the struct
o
