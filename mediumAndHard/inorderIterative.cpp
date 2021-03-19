#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<int> inOrder(Node *root)
{
    //code here
    vector<int> result;
    stack<Node *> st;

    Node *temp = root;
    while (temp || !st.empty())
    {
        while (temp != NULL)
        {
            st.push(temp);
            temp = temp->left;
        }
        temp = st.top();
        st.pop();

        result.push_back(temp->data);
        temp = temp->right;
    }
    return result;
}