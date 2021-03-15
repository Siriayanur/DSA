#include <iostream>
#include <climits>

using namespace std;

int sb(int a[], int n, int x)
{
    // Your code goes here
    int i = 0, j = 0;
    long long sum = 0;
    int minLen = INT_MAX;

    while (j < n)
    {
        sum += a[j];
        if (sum < x)
        {
            j++;
        }
        else
        {
            while (sum - a[i] > x)
            {
                sum -= a[i];
                i++;
            }
            minLen = min(minLen, j - i + 1);
            j++;
        }
    }
    return minLen;
}