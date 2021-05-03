#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
}

class Solution
{
public:
    //Function to convert binary tree to doubly linked list and return it.

    void helper(Node *root, Node *&head, Node *&tail)
    {
        if (!root)
            return;

        helper(root->left, head, tail);

        //Work at root
        if (!head)
        {
            head = root;
            tail = root;
        }
        else
        {
            tail->right = root;
            root->left = tail;
            tail = root;
        }

        helper(root->right, head, tail);
    }

    Node *bToDLL(Node *root)
    {
        //your code here
        Node *head = NULL, *tail = NULL;
        helper(root, head, tail);
        return head;
    }
};