void helper(Node *root, int l, int h, bool &deadEnd)
{
    if (!root || deadEnd)
    {
        return;
    }
    if (!root->left && !root->right)
    {
        if (l == h)
        {
            deadEnd = true;
        }
        return;
    }
    helper(root->left, l, root->data - 1, deadEnd);
    helper(root->right, root->data + 1, h, deadEnd);
}

bool isDeadEnd(Node *root)
{
    //Your code here
    bool deadEnd = false;
    helper(root, 1, INT_MAX, deadEnd);

    return deadEnd;
}