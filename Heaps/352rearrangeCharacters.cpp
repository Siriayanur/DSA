#include <bits/stdc++.h>
using namespace std;

string rearrangeString(string s)
{

    int n = s.length();

    unordered_map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
    }
    priority_queue<pair<int, char>, vector<pair<int, char>>> q;
    unordered_map<char, int>::iterator itr;
    for (itr = mp.begin(); itr != mp.end(); itr++)
    {
        q.push(make_pair(itr->second, itr->first)); //first one is number and second one is character
    }
    string result = "";
    pair<int, char> y(-1, '+');
    while (!q.empty())
    {
        pair<int, char> x = q.top();
        q.pop();
        result += x.second;
        if (y.first > 0)
        {
            q.push(make_pair(y.first, y.second));
        }
        x.first -= 1; //frequency of top element decreased
        y.first = x.first;
        y.second = x.second;
    }
    if (n != result.length())
        return s;

    return result;
}