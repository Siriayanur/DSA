#include <bits/stdc++.h>
using namespace std;

// Given an array of random elements get the k largest elements into result vector

vector<int> kLargest(int arr[], int n, int k)
{
    // code here
    vector<int> result;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    while ((k--) && !pq.empty())
    {
        int temp = pq.top();
        pq.pop();
        result.push_back(temp);
    }
    return result;
}
int main()
{
    int arr[5] = {349, 4, 21, 50, 42};
    vector<int> result = kLargest(arr, 5, 3);
    return 0;
}