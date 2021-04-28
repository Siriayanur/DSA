#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

// Should return true if tree is Sum Tree, else false
class Pair
{
public:
    int sum;
    bool isSum;
};
class Solution
{
public:
    Pair isSumHelper(Node *root)
    {

        if (!root)
        {
            Pair ans;
            ans.sum = 0;
            ans.isSum = true;
            return ans;
        }

        if (!root->left && !root->right)
        {
            Pair ans;
            ans.sum = root->data;
            ans.isSum = true;

            return ans;
        }

        Pair leftAns = isSumHelper(root->left);
        Pair rightAns = isSumHelper(root->right);

        Pair ans;

        ans.sum = leftAns.sum + rightAns.sum;

        if (ans.sum == root->data && leftAns.isSum && rightAns.isSum)
        {
            ans.isSum = true;
            ans.sum += root->data;
        }
        else
        {
            ans.isSum = false;
        }
        ans.sum += root->data;

        return ans;
    }

    bool isSumTree(Node *root)
    {
        // Your code here
        return isSumHelper(root).isSum;
    }
};