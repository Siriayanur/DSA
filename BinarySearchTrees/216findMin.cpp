#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;

    Node(int x)
    {
        data = x;
        right = NULL;
        left = NULL;
    }
};

// your task is to complete the below function
int minValue(Node *root)
{
    // Code here
    while (root && root->left)
    {
        root = root->left;
    }
    return root->data;
}