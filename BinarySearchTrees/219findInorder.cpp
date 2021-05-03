
#include <iostream>
#include "structureBT.h"
using namespace std;
void helper(node *root, node *&prev)
{
    if (!root)
        return;

    helper(root->left, prev);

    if (prev != NULL)
    {
        prev->next = root;
    }
    prev = root;

    helper(root->right, prev);
}

void populateNext(struct node *p)
{

    // Your code goes here
    node *prev = NULL;
    helper(p, prev);
}