#include <unordered_map>
#include <iostream>
using namespace std;

string solve(Node *root, unordered_map<string, int> &m)
{
    if (!root)
        return "$";

    string s = "";
    s += to_string(root->data);
    s += solve(root->left, m);
    s += solve(root->right, m);
    m[s]++;
    return s;
}

bool dupSub(Node *root)
{
    //your code here
    unordered_map<string, int> m;
    solve(root, m);
    for (auto a : m)
    {
        if (a.second >= 2 && a.first.length() > 3)
        {
            return true;
        }
    }
    return false;
}