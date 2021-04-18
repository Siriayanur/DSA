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

// Should return  right view of tree
class Solution
{
public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        // Your Code here
        vector<int> result;
        if (root == NULL)
            return result;

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

                if (temp->right)
                    pq.push(temp->right);

                if (temp->left)
                    pq.push(temp->left);
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
};