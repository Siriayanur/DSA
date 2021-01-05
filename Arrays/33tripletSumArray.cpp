#include <iostream>
#include <algorithm>
using namespace std;

bool twoSum(int arr[], int n, int sum, int start)
{
    int i = start;
    int j = n - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] > sum)
        {
            j--;
        }
        else if (arr[i] + arr[j] < sum)
        {
            i++;
        }
        else
        {
            return true;
        }
    }
    return false;
}

bool findSumX(int arr[], int n, int sum)
{
    sort(arr, arr + n);
    for (int i = 0; i < n - 2; i++)
    {
        if (twoSum(arr, n, sum - arr[i], i + 1))
        {
            return true;
        }
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
        int n, sum;
        cin >> n >> sum;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (findSumX(a, n, sum))
        {
            cout << "1" << endl;
        }
        else
        {
            cout << "0" << endl;
        }
    }
    return 0;
}
