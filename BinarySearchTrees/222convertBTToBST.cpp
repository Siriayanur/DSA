#include <structureBT.h>

#include <queue>

typedef priority_queue<int, vector<int>, greater<int>> pqmin;

class Solution
{
public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST

    void inorder(Node *root, pqmin &pq)
    {
        if (!root)
            return;

        inorder(root->left, pq);

        pq.push(root->data);

        inorder(root->right, pq);
    }

    void inorderFill(Node *root, pqmin &pq)
    {
        if (!root)
            return;

        inorderFill(root->left, pq);

        int current = pq.top();
        pq.pop();
        root->data = current;

        inorderFill(root->right, pq);
    }

    Node *binaryTreeToBST(Node *root)
    {
        //Your code goes here
        pqmin pq;

        inorder(root, pq);

        inorderFill(root, pq);

        return root;
    }
};