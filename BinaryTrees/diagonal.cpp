#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

vector<int> diagonal(Node *root)
{
    // your code here
    queue<Node *> q;
    vector<int> result;
    q.push(root);
    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        while (current)
        {

            if (current->left)
                q.push(current->left);

            result.push_back(current->data);
            current = current->right;
        }
    }
    return result;
}