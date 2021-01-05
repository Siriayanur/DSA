#include <iostream>
#include <climits>
using namespace std;

int trappingRainWaterNaives(int a[], int n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int max1 = -1, max2 = -1;
        for (int j = 0; j < i; j++)
        {
            max1 = max(max1, a[j]);
        }
        for (int j = i + 1; j < n; j++)
        {
            max2 = max(max2, a[j]);
        }
        result = result + (min(max1, max2) - a[i]);
    }
    return result;
}

int trappingRainWaterBetter(int a[], int n)
{

    int left[n], right[n];
    int result = 0;
    int maxEl = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxEl = max(maxEl, a[i]);
        left[i] = maxEl;
    }
    maxEl = INT_MIN;
    for (int i = n - 1; i > 0; i--)
    {
        maxEl = max(maxEl, a[i]);
        right[i] = maxEl;
    }
    for (int i = 0; i < n; i++)
    {
        int x = left[i];
        int y = right[i];
        result = result + (min(x, y) - a[i]);
    }
    return result;
}