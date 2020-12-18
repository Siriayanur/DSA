#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void sort012(int a[], int n)
{
    int start = 0, mid = 0, end = n - 1;
    while (mid <= end)
    {
        switch (a[mid])
        {
        case 0:
            swap(a[start++], a[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(a[mid], a[end--]);
            break;
        }
    }
}

int main()
{
    // int a[] = {0, 2, 1, 1, 1, 2, 2, 0, 2, 1, 2, 1, 0, 0};

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort012(a, n);
    return 0;
}