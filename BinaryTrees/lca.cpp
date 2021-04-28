#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

Node *lca(Node *root, int n1, int n2)
{
    //Your code here
    if (!root)
        return NULL;
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *leftAns = lca(root->left, n1, n2);
    Node *rightAns = lca(root->right, n1, n2);

    if (!leftAns && !rightAns)
    {
        return NULL;
    }
    if (leftAns && !rightAns)
    {
        return leftAns;
    }
    else if (rightAns && !leftAns)
    {
        return rightAns;
    }
    else
    {
        return root;
    }
}