#include <iostream>
using namespace std;

bool isHeap(Node *root)
{
    // Your code here
    if (root == NULL)
        return true;

    if (root->left == NULL && root->right == NULL)
        return true;

    if (root->right != NULL)
        if (root->right->data > root->data)
            return false;

    if (root->left != NULL)
        if (root->left->data > root->data)
            return false;

    return isHeap(root->right) && isHeap(root->left);
}