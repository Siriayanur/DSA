#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

//For int type
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

// For long long type
long long findMinDiff(vector<long long> a, long long n, long long m)
{
    //code
    if (n < m)
    {
        return -1;
    }
    if (n == 0 || m == 0)
    {
        return 0;
    }

    sort(a.begin(), a.end());
    long long minDifference = INT_MAX;
    for (long long i = 0; i + m - 1 < n; i++)
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