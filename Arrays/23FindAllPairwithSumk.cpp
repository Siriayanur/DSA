#include <bits/stdc++.h>
using namespace std;

int getPairsCount(int a[], int n, int k)
{
    // code here
    int pairs = 0;
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        map[a[i]]++;
    }
    // cout << endl;
    for (int i = 0; i < n; i++)
    {

        if (map[k - a[i]] > 0 && map[a[i]] > 0)
        {
            /* If the element is half the sum and is present in more amount */
            if (a[i] == (k - a[i]))
            {
                if (map[a[i]] == n)
                {
                    pairs = ((n * (n - 1)) / 2);
                    return pairs;
                }
                else if (map[k - a[i]] > 1)
                {
                    pairs = pairs + ((map[a[i]] * (map[a[i]] - 1)) / 2);
                }
                else
                {
                    continue;
                }
            }
            else
            {
                pairs = pairs + (map[a[i]] * map[k - a[i]]);
            }
            cout << a[i] << " " << k - a[i] << " " << map[a[i]] << " " << map[k - a[i]] << " " << pairs << endl;

            map[a[i]] = 0;
            map[k - a[i]] = 0;
        }
    }
    return pairs;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << getPairsCount(a, n, k) << endl;
    return 0;
}