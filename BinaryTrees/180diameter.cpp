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

class Pair
{

public:
    int height;
    Node *root;
    int diameter;
};

class Solution
{
public:
    //Function to return the diameter of a Binary Tree.

    Pair helper(Node *root)
    {
        if (root == NULL)
        {
            Pair ans;
            ans.height = 0;
            ans.root = root;
            ans.diameter = 0;
            return ans;
        }

        if (!root->left && !root->right)
        {
            Pair ans;
            ans.height = 1;
            ans.root = root;
            ans.diameter = 1;
            return ans;
        }

        Pair leftAns, rightAns;

        leftAns = helper(root->left);

        rightAns = helper(root->right);

        Pair ans;
        ans.root = root;
        ans.height = 1 + max(leftAns.height, rightAns.height);
        ans.diameter = max(leftAns.diameter, max(rightAns.diameter, 1 + leftAns.height + rightAns.height));

        return ans;
    }

    int diameter(Node *root)
    {
        // Your code here

        return helper(root).diameter;
    }
};
