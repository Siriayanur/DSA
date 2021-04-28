#include <bits/stdc++.h>
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

class Pair
{
public:
    int height;
    bool isbalanced;
};

Pair helper(Node *root)
{
    if (root == NULL)
    {
        Pair ans;
        ans.height = 0;
        ans.isbalanced = true;
        return ans;
    }

    Pair leftAns = helper(root->left);
    Pair rightAns = helper(root->right);

    if (leftAns.isbalanced && rightAns.isbalanced)
    {
        if (abs(leftAns.height - rightAns.height) <= 1)
        {
            Pair ans;
            ans.height = 1 + max(leftAns.height, rightAns.height);
            ans.isbalanced = true;
            return ans;
        }
    }
    else
    {
        Pair ans;
        ans.height = 1 + max(leftAns.height, rightAns.height);
        ans.isbalanced = false;
        return ans;
    }
}

//Function to check whether a binary tree is balanced or not.
bool isBalanced(Node *root)
{
    //  Your Code here
    return helper(root).isbalanced;
}
