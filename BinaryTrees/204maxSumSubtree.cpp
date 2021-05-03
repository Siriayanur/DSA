#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
int findMaxSum(Node *root, int &ans)
{
    if (!root)
        return 0;

    int currentSum = root->data + findMaxSum(root->left, ans) + findMaxSum(root->right, ans);
    ans = max(ans, currentSum);
    return currentSum;
}

int findMaxSumHelper(Node *root)
{

    int ans = INT_MIN;
    findMaxSum(root, ans);
}