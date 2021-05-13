#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;
/**
 * 1) o(n*n) : Naive
 * 2) o(nlogn) : Optimised
 * 3) o(n) o(n)space : Optimised
 * 
 * 
 * 
*/
string isSubset1(int a1[], int a2[], int n, int m)
{
    int j;
    int i;
    for (i = 0; i < m; i++)
    {
        for (j = 0; i < n; i++)
        {
            if (a1[j] == a2[i])
                break;
        }
        if (j == n)
            return "No";
    }
    return "yes";
}

bool binarySearch(int l, int h, int a[], int target)
{
    if (l > h)
    {
        return false;
    }
    int mid = (l + h) / 2;

    if (target == a[mid])
        return true;

    else if (target < a[mid])
        return binarySearch(l, mid - 1, a, target);
    else if (target > a[mid])
        return binarySearch(mid + 1, h, a, target);
}

string isSubset2(int a1[], int a2[], int n, int m)
{
    sort(a1, a1 + n);
    for (int i = 0; i < m; i++)
    {
        if (!binarySearch(0, n - 1, a1, a2[i]))
            return "No";
    }
    return "Yes";
}
string isSubset3(int a1[], int a2[], int n, int m)
{
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        map[a1[i]]++;
    }

    for (int i = 0; i < m; i++)
    {
        if (map.count(a2[i]) == 0)
        {
            return "No";
        }
    }
    return "Yes";
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++)
        {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> a2[i];
        }

        cout << isSubset3(a1, a2, n, m) << endl;
    }
    return 0;
}