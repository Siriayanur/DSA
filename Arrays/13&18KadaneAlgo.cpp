#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int a[], int n)
{

    // Your code here
    int currentMax = a[0];
    int finalMax = a[0];
    for (int i = 1; i < n; i++)
    {
        currentMax = max(a[i], currentMax + a[i]);
        if (currentMax > finalMax)
        {
            finalMax = currentMax;
        }
    }
    return finalMax;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << maxSubarraySum(a, n);
    return 0;
}