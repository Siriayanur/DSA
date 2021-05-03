#include <structureBT.h>

class Solution
{
public:
    // Return the Kth smallest element in the given BST
    void inorder(Node *root, int &k, int &n, int &result)
    {
        if (!root || n >= k)
        {
            return;
        }
        inorder(root->left, k, n, result);

        n++;
        if (n == k)
        {
            result = root->data;
            return;
        }

        inorder(root->right, k, n, result);
    }
    int KthSmallestElement(Node *root, int K)
    {
        //add code here.
        int result = -1;
        int n = 0;
        inorder(root, K, n, result);
        return result;
    }
};