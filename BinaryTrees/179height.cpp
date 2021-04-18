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

class Solution
{
public:
    //Function to find the height of a binary tree.
    int height(struct Node *node)
    {
        // code here
        if (node == NULL)
            return 0;

        int leftAns = (node->left ? height(node->left) : 0);
        int rightAns = (node->right ? height(node->right) : 0);

        return 1 + max(leftAns, rightAns);
    }
};