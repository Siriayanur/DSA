#include <structureBT.h>

bool isPresent(Node *root, int data)
{
    if (!root)
        return false;
    if (root->data == data)
        return true;
    if (data < root->data)
        return isPresent(root->left, data);

    if (data > root->data)
        return isPresent(root->right, data);
}
int countPairs(Node *root1, Node *root2, int x)
{
    // Code here
    if (!root1)
        return 0;

    if (isPresent(root2, x - root1->data))
    {
        return 1 + countPairs(root1->left, root2, x) + countPairs(root1->right, root2, x);
    }
    return countPairs(root1->left, root2, x) + countPairs(root1->right, root2, x);
}