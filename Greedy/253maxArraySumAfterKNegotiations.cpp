#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long int maxSum(long long int a[], int n, int k)
{

    sort(a, a + n);
    int i = 0;
    while (k > 0)
    {
        if (a[i] == 0)
        {
            break;
        }
        else
        {
            a[i] = -1 * a[i];
            k--;
            if (i == n - 1)
            {
                continue;
            }
            if (a[i + 1] < 0 || a[i] > a[i + 1])
            {
                i++;
            }
        }
    }

    long long int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += a[i];
    }
    return totalSum;
}

int main()
{

    long long int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        long long int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << maxSum(a, n, k) << endl;
    }
}