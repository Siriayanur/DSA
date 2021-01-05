#include <iostream>
#include <algorithm>

using namespace std;

long long int maxProduct(int a[], int n)
{

    long long int maxp, minp, result;
    maxp = minp = result = 1;

    for (int i = 0; i < n; i++)
    {
        long long int x = a[i];
        if (x < 0)
        {
            swap(minp, maxp);
        }

        minp = min(x, x * a[i]);
        maxp = max(x, x * a[i]);
        result = max(maxp, result);
    }
    return result;
}
