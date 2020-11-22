#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string solve(int arr[], int n)
{
    sort(arr, arr + n);
    string ans;
    int carry = 0;
    int i;
    for (i = n - 1; (i - 1) >= 0;)
    {
        int curr = arr[i] + arr[i - 1] + carry;
        carry = curr / 10;
        curr = curr % 10;
        ans = to_string(curr) + ans;
        i -= 2;
    }

    ans = to_string(carry + arr[i]) + ans;
    i = 0;
    while (ans[i] == '0')
        i++;
    return ans.substr(i);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int element : arr)
    {
        cin >> element;
    }
    cout << solve(arr, n);
    return 0;
}