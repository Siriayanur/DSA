#include <structureBT.h>

class Solution
{
public:
    void inorderReverse(Node *root, int k, int &result, int &n)
    {
        if (!root || n >= k)
            return;

        inorderReverse(root->right, k, result, n);
        n++;
        if (k == n)
        {
            result = root->data;
            return;
        }

        inorderReverse(root->left, k, result, n);
    }

    int kthLargest(Node *root, int K)
    {
        //Your code here
        int k = K;
        int result = 0;
        int n = 0;
        inorderReverse(root, k, result, n);
        return result;
    }
};
