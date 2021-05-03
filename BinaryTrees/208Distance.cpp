#include <iostream>
#include "structureBT.h"
using namespace std;

int distance(Node *root, int data)
{
    if (!root)
        return -1;

    int dist = -1;
    if (root->data == data || (dist = distance(root->left, data)) >= 0 || (dist = distance(root->right, data)) >= 0)
        return dist + 1;
    return dist;
}

Node *lca(Node *root, int n1, int n2)
{
    //Your code here
    if (!root)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;

    Node *leftAns = lca(root->left, n1, n2);
    Node *rightAns = lca(root->right, n1, n2);

    if (!leftAns && !rightAns)
        return NULL;

    else if (leftAns && !rightAns)
        return leftAns;

    else if (rightAns && !leftAns)
        return rightAns;

    else
        return root;
}
int findDist(Node *root, int a, int b)
{
    // Your code here
    int lcaDist = 0;

    int first = distance(root, a);

    int second = distance(root, b);

    Node *temp = lca(root, a, b);

    return distance(temp, a) + distance(temp, b);
}