#include <bits/stdc++.h>
using namespace std;

vector<int> topView(struct Node *root)
{
    queue<pair<Node *, int>> q;
    map<int, int> mp;
    vector<int> result;

    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node *, int> current = q.front();
        q.pop();
        if (mp.find(current.second) == mp.end())
            mp[current.second] = current.first->data;

        if (current.first->left)
            q.push(make_pair(current.first->left, current.second - 1));
        if (current.first->right)
            q.push(make_pair(current.first->right, current.second + 1));
    }
    auto x = mp.begin();
    while (x != mp.end())
    {
        result.push_back(x->second);
        x++;
    }
    return result;
}
