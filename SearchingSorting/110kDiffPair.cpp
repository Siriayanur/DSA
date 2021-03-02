

/*
  Brute Force o(n*n) 
  Sort + Search =>  
     o(nlogn) + binarysearch(arr[i]+k,range(i+1,n-1));
  Sort + Iterate =>
     o(nlogn) + i->0 and j->n-1 ++ and -- according to the sum
*/

#include <bits/stdc++.h>
using namespace std;

bool findPairWithDiffk(int a[], int n, int k)
{
    sort(a, a + n);
    int i = 0, j = 1;
    while (i < n && j < n)
    {
        int diff = a[j] - a[i];
        if (diff == k)
        {
            return true;
        }
        else if (diff > k)
            i++;
        else if (diff < k)
            j++;
    }
    return false;
}

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n;
        int a[n];

        cin >> k;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (findPairWithDiffk(a, n, k))
            cout << "1" << endl;
        else
            cout << "-1" << endl;
    }
    return 0;
}