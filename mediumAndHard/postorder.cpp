#include <stack>
#include <iostream>
#include <vector>

using namespace std;

vector<int> postOrder2(Node *node)
{
    // code here
    stack<Node *> s1;
    stack<Node *> s2;
    vector<int> result;

    s1.push(node);
    while (!s1.empty())
    {
        Node *temp = s1.top();
        s1.pop();

        s2.push(temp);

        if (temp->left)
            s1.push(temp->left);
        if (temp->right)
            s1.push(temp->right);
    }
    while (!s2.empty())
    {
        Node *curr = s2.top();
        result.push_back(curr->data);
        s2.pop();
    }
    return result;
}

vector<int> postOrder(Node *node)
{
    stack<Node *> s;
    s.push(node);
    vector<int> result;
    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        result.push_back(temp->data);
        if (temp->left)
            s.push(temp->left);
        if (temp->right)
            s.push(temp->right);
    }
    reverse(result.begin(), result.end());
    return result;
}