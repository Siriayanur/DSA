#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
vector<int> preOrder(Node *root)
{
    //code here
    stack<Node *> st;
    vector<int> result;
    st.push(root);

    while (!st.empty())
    {
        Node *temp = st.top();
        st.pop();

        result.push_back(temp->data);

        if (temp->right != NULL)
        {
            st.push(temp->right);
        }
        if (temp->left != NULL)
        {
            st.push(temp->left);
        }
    }
    return result;
}