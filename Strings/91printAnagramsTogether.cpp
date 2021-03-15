#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> Anagrams(vector<string> &string_list)
{
    // Your Code Here
    unordered_map<string, int> store;

    unordered_map<string, vector<string>> result;
    for (int i = 0; i < string_list.size(); i++)
    {
        string s = string_list[i];
        sort(s.begin(), s.end());

        if (store.find(s) == store.end())
            store[s]++;

        result[s].push_back(string_list[i]);
    }
    vector<vector<string>> answer;
    for (auto i : result)
    {
        answer.push_back(i.second);
    }
    return answer;
}