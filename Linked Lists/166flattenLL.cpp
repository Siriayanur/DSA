#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

/*  Function which returns the  root of 
    the flattened linked list. */

Node *merge(Node *a, Node *b)
{
    if (!a)
        return b;
    if (!b)
        return a;
    if (a->data <= b->data)
    {
        a->bottom = merge(a->bottom, b);
        return a;
    }
    else
    {
        b->bottom = merge(a, b->bottom);
        return b;
    }
}

Node *flatten(Node *root)
{
    // Your code here
    if (!root || !root->next)
        return root;

    Node *thirdNode = root->next->next;
    Node *temp = merge(root, root->next);
    temp->next = thirdNode;
    return flatten(temp);
}