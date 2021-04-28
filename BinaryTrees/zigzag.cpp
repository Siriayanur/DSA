#include <bits/stdc++.h>
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

//Function to store the zig zag order traversal of tree in a list.
vector<int> zigZagTraversal(Node *root)
{
    // Code here
    vector<int> result;
    stack<Node *> s1;
    stack<Node *> s2;
    Node *top1;
    Node *top2;
    s1.push(root);
    while (!s1.empty() || !s2.empty())
    {

        while (!s1.empty())
        {
            top1 = s1.top();
            result.push_back(top1->data);
            if (top1->left)
                s2.push(top1->left);

            if (top1->right)
                s2.push(top1->right);

            s1.pop();
        }
        while (!s2.empty())
        {
            top2 = s2.top();
            result.push_back(top2->data);
            if (top2->right)
                s1.push(top2->right);

            if (top2->left)
                s1.push(top2->left);

            s2.pop();
        }
    }
    return result;
}