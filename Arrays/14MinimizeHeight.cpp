#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int getMinDiff(int a[], int n, int k)
{
    // code here
    sort(a, a + n);
    int start = a[0] = a[0] + k;
    int end = a[n - 1] = a[n - 1] - k;

    int range = a[n - 1] - a[0];

    if (start > end)
    {
        swap(start, end);
    }

    for (int i = 1; i < n - 1; i++)
    {
        int currentStart = a[i] - k;
        int currentEnd = a[i] + k;
        if (currentStart >= start || currentEnd <= end)
        {
            continue;
        }

        if (currentEnd - start <= end - currentStart)
        {
            start = currentStart;
        }
        else
        {
            end = currentEnd;
        }
    }
    return min(range, end - start);
}
int main()
{
    int a[] = {1, 8, 5, 10};
    cout << getMinDiff(a, 4, 2);
    return 0;
}