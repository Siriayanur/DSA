#include <iostream>
using namespace std;
typedef long long int ll;

ll FindMaxSum(ll a[], ll n)
{
    // Your code here

    if (n == 0)
    {
        return 0;
    }

    ll val1 = a[0];
    if (n == 1)
    {
        return val1;
    }

    ll val2 = max(a[1], a[0]);
    if (n == 2)
    {
        return val2;
    }

    ll maxVal;
    for (ll i = 2; i < n; i++)
    {
        maxVal = max(a[i] + val1, val2);
        val1 = val2;
        val2 = maxVal;
    }
    return maxVal;
}
