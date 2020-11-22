#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //code
    int t;
    cin >> t;
    int n, k;
    while (t--)
    {
        cin >> n;
        cin >> k;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);

        // 1 2 3 4

        int minAmount = 0;
        int i = 0, j = n - 1;
        while (i <= j)
        {
            minAmount += a[i];
            j = j - k;
            i++;
        }

        int maxAmount = 0;
        int x = 0, y = n - 1;
        while (x <= y)
        {
            maxAmount += a[y];
            y--;
            x = x + k;
        }
        cout << minAmount << " " << maxAmount << endl;
    }
    return 0;
}