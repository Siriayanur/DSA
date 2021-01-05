#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int minDifference(int a[], int n, int m)
{
    if (n < m)
    {
        return -1;
    }
    if (n == 0 || m == 0)
    {
        return 0;
    }

    sort(a, a + n);
    int minDifference = INT_MAX;
    for (int i = 0; i + m - 1 < n; i++)
    {
        minDifference = min(minDifference, a[i + m - 1] - a[i]);
    }
    return minDifference;
}

int main()
{
    //code
    int t;
    int n, m;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cin >> m;
        cout << minDifference(a, n, m) << endl;
    }
    return 0;
}