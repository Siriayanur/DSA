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
Node *insert(Node *root, int Key)
{
    if (!root)
    {
        Node *newNode = new Node(Key);
        return newNode;
    }
    if (root->data == Key)
        return root;
    if (Key < root->data)
        root->left = insert(root->left, Key);

    if (Key > root->data)
        root->right = insert(root->right, Key);

    return root;
}