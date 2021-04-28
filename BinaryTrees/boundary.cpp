#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};

void getLeftStuff(Node *root, vector<int> &result)
{
    if (!root)
    {
        return;
    }

    if (root->left)
    {

        result.push_back(root->data);
        getLeftStuff(root->left, result);
    }
    else if (root->right)
    {

        result.push_back(root->data);
        getLeftStuff(root->right, result);
    }
}

void getLeafStuff(Node *root, vector<int> &result)
{

    if (!root)
        return;

    getLeafStuff(root->left, result);

    if (!root->left && !root->right)
    {
        result.push_back(root->data);
    }

    getLeafStuff(root->right, result);
}

void getRightStuff(Node *root, vector<int> &result)
{
    if (!root)
        return;

    if (root->right)
    {
        getRightStuff(root->right, result);
        result.push_back(root->data);
    }
    else if (root->left)
    {
        getRightStuff(root->left, result);
        result.push_back(root->data);
    }
}

vector<int> printBoundary(Node *root)
{
    //Your code herere
    vector<int> result;

    result.push_back(root->data);

    getLeftStuff(root->left, result);

    getLeafStuff(root, result);

    getRightStuff(root->right, result);

    return result;
}