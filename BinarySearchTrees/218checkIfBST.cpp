#include <iostream>
#include "structureBT.h"
using namespace std;

// return true if the given tree is a BST, else return false
class Solution
{
public:
    bool helper(Node *root, int left, int right)
    {

        if (!root)
            return true;

        if (root->data < left || root->data > right)
        {
            return false;
        }

        if (left > right)
        {
            return false;
        }

        return helper(root->left, left, root->data - 1) && helper(root->right, root->data + 1, right);
    }

    bool isBST(Node *root)
    {
        // Your code here
        return helper(root, INT_MIN, INT_MAX);
    }
};
