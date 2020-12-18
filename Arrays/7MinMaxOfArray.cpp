#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int n;
    while (t--)
    {
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int minEl = INT_MAX, maxEl = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            minEl = min(minEl, a[i]);
            maxEl = max(maxEl, a[i]);
        }
        cout << minEl << " " << maxEl << endl;
    }
    return 0;
}