#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

//Print the subarrays
vector<pair<int, int>> findSubArray(vector<ll> arr, int n)
{
    vector<pair<int, int>> result;

    unordered_map<int, vector<int>> map;

    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == 0)
        {
            result.push_back(make_pair(0, i));
        }

        if (map.find(sum) != map.end())
        {
            vector<int> m = map[sum];
            for (auto it = m.begin(); it != m.end(); it++)
            {
                result.push_back(make_pair(*it + 1, i));
            }
        }
        map[sum].push_back(i);
    }

    return result;
}

//Return the count of such subarrays
ll findSubArrayCount(vector<ll> arr, int n)
{
    //code here
    unordered_map<int, int> map;
    ll count = 0;
    ll sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            count++;
        }
        if (map.find(sum) != map.end())
        {
            count += map[sum];
        }
        map[sum]++;
    }
    return count;
}

int main()
{
}