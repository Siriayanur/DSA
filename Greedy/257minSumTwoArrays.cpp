#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minSum(int a[], int b[], int n)
{

    sort(a, a + n);
    sort(b, b + n);
    int minSum = 0;
    for (int i = 0; i < n; i++)
    {
        minSum += abs(a[i] - b[i]);
    }
    return minSum;
}

int main()
{
    int n;
    cin >> n;

    int a[n];
    int b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    cout << minSum(a, b, n) << endl;
    return 0;
}