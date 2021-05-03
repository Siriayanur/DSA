#include <structureBT.h>

int getCount(Node *root, int l, int h)
{
    // your code goes here
    if (!root)
        return 0;

    if (root->data < l)
        return getCount(root->right, l, h);

    if (root->data > h)
        return getCount(root->left, l, h);

    if (root->data <= h && root->data >= l)
        return 1 + getCount(root->left, l, h) + getCount(root->right, l, h);
}