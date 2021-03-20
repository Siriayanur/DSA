#include <bits/stdc++.h>
using namespace std;

string reorganizeString1(string S)
{

    unordered_map<char, int> map;
    for (int i = 0; i < S.length(); i++)
    {
        map[S[i]]++;
    }

    priority_queue<pair<int, char>> pq;

    for (auto t : map)
    {
        pq.push(make_pair(t.second, t.first));
        cout << "Populated" << endl;
    }

    string res = "";
    pair<int, char> prev = make_pair(-1, '#');

    while (!pq.empty())
    {
        pair<int, char> temp = pq.top();
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();

        res = res + temp.second;

        if (prev.first > 0)
        {
            pq.push(prev);
        }
        (temp.first)--;
        prev = temp;
    }

    if (res.size() == S.size())
    {
        return res;
    }
    else
        return "";
}
string reorganizeString2(string s)
{
    map<char, int> mp;
    for (auto x : s)
        mp[x]++;
    priority_queue<pair<int, char>> p;
    for (auto it : mp)
        p.push({it.second, it.first});
    string ans;
    while (p.size() > 1)
    {
        auto k = p.top();
        p.pop();
        ans += k.second;
        k.first--;
        auto l = p.top();
        p.pop();
        ans += l.second;
        l.first--;
        if (k.first > 0)
            p.push(k);
        if (l.first > 0)
            p.push(l);
    }
    if (p.size() == 0)
        return ans;
    if (p.top().first > 1)
        return "";
    return ans + p.top().second;
}
int main()
{
    string s = "aab";
    cout << reorganizeString(s) << endl;
    return 0;
}