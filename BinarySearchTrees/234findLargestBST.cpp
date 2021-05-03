#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
class BST
{
public:
    bool isBST;
    int size;
    int min;
    int max;
};

/*You are required to complete this method */
// Return the size of the largest sub-tree which is also a BST
BST helper(Node *root)
{

    //POSTORDER TRAVERSAL
    if (!root)
    {
        BST ans;
        ans.isBST = true;
        ans.size = 0;
        ans.min = INT_MAX;
        ans.max = INT_MIN;
        return ans;
    }

    BST leftAns = helper(root->left);
    BST rightAns = helper(root->right);

    BST ans;
    if (leftAns.isBST && rightAns.isBST && root->data > leftAns.max && root->data < rightAns.min)
    {
        ans.isBST = true;
        ans.size = 1 + rightAns.size + leftAns.size;
        ans.min = min(root->data, leftAns.min);
        ans.max = max(root->data, rightAns.max);
    }
    else
    {
        ans.isBST = false;
        ans.size = max(leftAns.size, rightAns.size);
        ans.min = -1;
        ans.max = -1;
    }
    return ans;
}

int largestBst(Node *root)
{
    //Your code here
    return helper(root).size;
}