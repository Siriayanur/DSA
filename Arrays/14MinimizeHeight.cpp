#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

//Correct answer
int getMinDiff(int a[], int n, int k)
{
    sort(a, a + n);
    int minEl, maxEl;
    int result = a[n - 1] - a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] >= k)
        {
            maxEl = max(a[i - 1] + k, a[n - 1] - k);
            minEl = min(a[0] + k, a[i] - k);
            result = min(result, maxEl - minEl);
        }
    }
    return result;
}
int main()
{
    int a[] = {1, 8, 5, 10};
    cout << getMinDiff(a, 4, 2);
    return 0;
}