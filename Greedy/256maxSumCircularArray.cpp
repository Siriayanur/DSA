#include <bits/stdc++.h>
using namespace std;

int returnMaxSum(int a[], int n)
{
    sort(a, a + n);
    vector<int> result;
    for (int i = 0; i < n / 2; i++)
    {
        result.push_back(a[i]);
        result.push_back(a[n - i - 1]);
    }

    //If odd number of elements , push the middle element to the last

    if (n & 1)
    {
        result.push_back(a[n / 2]);
    }

    int maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        maxSum += abs(result[i] - result[i + 1]);
    }

    //the last element of the array + first element of the array -->-->cyclic fashion
    maxSum += abs(result[n - 1] - result[0]);
    return maxSum;
}

int main()
{
    int a[] = {1, 9, 4, 3, 10, 20, 5, 6};
    int n;
    n = 8;
    // cin >> n;
    // for (int i = 0; i < n; i++){
    //     cin >> a[i];
    // }
    cout << returnMaxSum(a, n) << endl;
    return 0;
}