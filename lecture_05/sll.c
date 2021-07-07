// Attempt at programming a complete singly linked list

#include <stdio.h>
#include <stdlib.h>

// Definition of the sll node
typedef struct node
{
    int number;
    struct node *next;
}
node;

// Function declarations
node *create(int num);
void print_list(node *list);
void append(node *list, int num);

int main(void)
{
    node *a = create(8);
    append(a, 8);
    append(a, 9);
    print_list(a);
}

// Initial node creation function
node *create(int num)
{
    node *n = malloc(sizeof(node));
    if (n != NULL)
    {
        n->number = num;
        n->next = NULL;
    }
    return n;
}

// Appending elements at the end of the list
void append(node *list, int num)
{
    // Create new node
    node *n = create(num);

    // Iterate to find last
    node *tmp = list;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    // Now tmp points to the last element, extend list pointing to new node
    tmp->next = n;
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

