#include <iostream>
using namespace std;

int minSwaps(int a[], int n, int k)
{

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > k)
        {
            count++;
        }
    }

    int bad = 0;
    for (int i = 0; i < count; i++)
    {
        if (a[i] > k)
        {
            bad++;
        }
    }

    int ans = bad;
    for (int i = 0, j = count; j < n; j++, i++)
    {

        if (a[i] > k)
        {
            bad--;
        }

        if (a[j] > k)
        {
            bad++;
        }

        ans = min(ans, bad);
    }
    return ans;
}