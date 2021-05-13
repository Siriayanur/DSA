#include <iostream>
#include <algorithm>

using namespace std;
/**
 * Analysis : 
 * arr  1 2 -2 9 5 0 3 -6
 * max = 2 ,  9 ,45, 3    
 * 
 * -2 -3 4 5 6 0 50
 * 
 * a[i],a[i]*min,a[i]*max
 * 
 * -2,-2,-2 
 * -3,6,6
 * 4,-12,24
 * 
 * min   -2  -3  -12 
 * max   -2  6   24
 * a[i]  -2  -3  4
 * 
*/

long long int maxProductSubArray(int a[], int n)
{
    long long int final_product = a[0];
    long long int max_ending = a[0], min_ending = a[0];

    for (int i = 1; i < n; i++)
    {
        long long int temp = max_ending;

        max_ending = max<long long int>(a[i], max<long long int>(max_ending * a[i], min_ending * a[i]));

        min_ending = min<long long int>(a[i], min<long long int>(temp * a[i], min_ending * a[i]));
        final_product = max<long long int>(final_product, max_ending);
    }
    return final_product;
}

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
