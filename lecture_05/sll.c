// Attempt at programming a complete singly linked list

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
void insert(node **list, int num);
bool search(node *list, int num);
void pop(node **list, int num);
void delete(node *list);

int main(void)
{
    node *a = create(1);
    append(a, 2);
    append(a, 3);
    append(a, 4);
    append(a, 5);
    insert(&a, 0);
    print_list(a);
    pop(&a, 1);
    pop(&a, 0);
    pop(&a, 5);
    print_list(a);
    delete(a);
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

// Add element at begginning of list
void insert(node **list, int num)
{
    node *n = create(num);
    n->next = *list;
    *list = n;
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

// Search if an element is on the list
bool search(node *list, int num)
{
    node *tmp = list;
    while (tmp != NULL)
    {
        if (tmp->number == num)
        {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

// Delete element from list, if contained
void pop(node **list, int num)
{
    node *tmp = *list;
    node *tmp0 = NULL;      // Previous node
    while (tmp != NULL)
    {
        if (tmp->number == num)
        {
            // If deleting node is the first
            if (tmp0 == NULL)
            {
                // Won't work, list is a copy of pointer list
                *list = (*list)->next;
                print_list(*list);
            }
            else
            {
                tmp0->next = tmp->next;
            }
            free(tmp);
            return;
        }
        // Edge case is when tmp0 is null
        tmp0 = tmp;
        tmp = tmp->next;
    }
}

// Recursively delete entire list
void delete(node *list)
{
    if (list->next == NULL)
    {
        free(list);
    }
    else
    {
        delete(list->next);
        free(list);
    }
}
