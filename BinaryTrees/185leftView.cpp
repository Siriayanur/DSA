#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
vector<int> leftView(Node *root)
{

    // Your code here
    vector<int> result;

    queue<Node *> pq;
    pq.push(root);
    pq.push(NULL);
    result.push_back(root->data);

    while (!pq.empty())
    {
        Node *temp = pq.front();
        pq.pop();

        if (temp != NULL)
        {

            if (temp->left)
                pq.push(temp->left);

            if (temp->right)
                pq.push(temp->right);
        }
        else if (temp == NULL)
        {

            if (!pq.empty() && pq.front() != NULL)
            {
                result.push_back(pq.front()->data);
                pq.push(NULL);
            }
        }
    }
    return result;
}