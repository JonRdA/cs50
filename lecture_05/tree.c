    // Code examples not a running file
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}
node;

// Searching algorithm in the tree
bool search(node *tree, int num)
{
    if (tree == NULL)
    {
        return false;
    }
    else if (num < tree->number)
    {
        return search(tree->left, num);
    }
    else if (num > tree->number)
    {
        return search(tree->right, num);
    }
    else
    {
        return true;
    }
}
