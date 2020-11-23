#include <bits/stdc++.h>
using namespace std;

long int maxSumIndex(int input[], int n)
{
    sort(input, input + n);

    long long int total = 0;
    for (int i = 1; i < n; i++)
    {
        total += (i * input[i]);
    }
    return (total % (long int)(pow(10, 9) + 7));
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int input[n];
        for (int i = 0; i < n; i++)
        {
            cin >> input[i];
        }
        cout << maxSumIndex(input, n) << endl;
    }
    return 0;
}