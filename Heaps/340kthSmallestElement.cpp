#include <bits/stdc++.h>

//Naive solution
int kthSmallest(int a[], int l, int r, int k)
{
    //code here
    priority_queue<int, vector<int>, greater<int>> p;
    for (int i = l; i <= r; i++)
    {
        p.push(a[i]);
    }
    while (k > 1)
    {
        // cout << p.top() << " ";
        p.pop();
        k--;
    }
    return p.top();
}

//Optimised Solution
int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}
int randomPartition(int arr[], int l, int r)
{
    int n = r - l + 1;
    int pivot = rand() % n;
    swap(arr[l + pivot], arr[r]);
    return partition(arr, l, r);
}

int kthSmallest(int arr[], int l, int r, int k)
{

    int pos = randomPartition(arr, l, r);

    if (pos - l == k - 1)
        return arr[pos];

    if (pos - l > k - 1)
        return kthSmallest(arr, l, pos - 1, k);
    return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
}