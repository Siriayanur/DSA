#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
class Solution
{
public:
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *root)
    {
        // Your code here

        if (!root)
            return;

        if (!root->left && !root->right)
        {
            root->data = 0;
            return;
        }

        root->data = (root->left ? root->left->data : 0);
        root->data += (root->right ? root->right->data : 0);

        toSumTree(root->left);
        toSumTree(root->right);

        root->data += (root->left ? root->left->data : 0);
        root->data += (root->right ? root->right->data : 0);
    }
};