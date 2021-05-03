#include <structureBT.h>

int findKthSmallest(Node *root, int k, int l = 0)
{
}

int findLength(Node *root)
{
    if (!root)
        return 0;
    1 + findLength(root->left) + findLength(root->right);
}

int medianOfBST(Node *root)
{
    int k;
    int n = findLength(root);
    if (n % 2 != 0)
    {
        findKthSmallest(root, n / 2);
    }
}