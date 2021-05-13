#include <bits/stdc++.h>
using namespace std;

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
int partition(int a[], int l, int r)
{
    int i = l;
    for (int j = l; j < r; j++)
    {
        if (a[r] >= a[j])
        {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[r]);
    return i;
}
int kthSmallest2(int arr[], int l, int r, int k)
{
    int m = rand() % (r - l + 1);
    swap(arr[l + m], arr[r]);
    int index = partition(arr, l, r);
    if (index - l + 1 == k)
    {
        return arr[index];
    }
    if (index - l + 1 > k)
    {
        return kthSmallest2(arr, l, index - 1, k);
    }
    return kthSmallest2(arr, index + 1, r, k - (index - l + 1));
}
int main()
{
    int a[] = {7, 10, 4, 3, 20, 15};
    cout << kthSmallest(a, 0, 5, 2) << endl;
    return 0;
}