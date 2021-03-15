#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

string secFrequent(string arr[], int n)
{
    //code here.
    map<string, int>::iterator it, max_it;
    map<string, int> map;

    for (int i = 0; i < n; i++)
    {
        map.insert(make_pair(arr[i], count(arr, arr + n, arr[i])));
    }

    max_it = map.begin();
    for (it = map.begin(); it != map.end(); it++)
    {
        if (it->second > max_it->second)
            max_it = it;
    }

    map.erase(max_it);
    max_it = map.begin();

    for (it = map.begin(); it != map.end(); it++)
    {
        if (it->second > max_it->second)
            max_it = it;
    }

    return max_it->first;
}

int main()
{
    vector<string> a(6);
    for (int i = 0; i < 6; i++)
    {
        string in;
        cin >> in;
        a.push_back(in);
    }
    cout << secFrequent(a, 6) << endl;
}