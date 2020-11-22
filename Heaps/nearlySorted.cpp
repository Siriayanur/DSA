#include <bits/stdc++.h>
using namespace std;

vector<int> nearlySorted(int arr[], int n, int k)
{
    // Your code here
    vector<int> result;
    if (k == n)
    {
        for (int i = 0; i < n; i++)
        {
            result.push_back(arr[i]);
        }
        return result;
    }
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr + k + 1);

    for (int i = k + 1; i < n; i++)
    {
        result.push_back(pq.top());
        pq.pop();
        pq.push(arr[i]);
    }
    while (!pq.empty())
    {
        result.push_back(pq.top());
        pq.pop();
    }
    return result;
}
vector<int> nearlySorted(int arr[], int n, int k)
{
    // Your code here
    vector<int> result;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    while (!pq.empty())
    {
        result.push_back(pq.top());
        pq.pop();
    }
    return result;
}
int main()
{
    return 0;
}