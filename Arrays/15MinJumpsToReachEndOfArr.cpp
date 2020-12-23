#include <bits/stdc++.h>
using namespace std;

int minJumps(int a[], int n)
{
    // Your code here
    if (n <= 1)
    {
        return 0;
    }

    if (a[0] == 0)
    {
        return -1;
    }

    int steps = a[0];
    int maxReachableIndex = a[0];
    int jump = 1;
    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
        {
            return jump;
        }

        maxReachableIndex = max(maxReachableIndex, i + a[i]);
        steps--;
        if (steps == 0)
        {
            jump++;
            if (i >= maxReachableIndex)
            {
                return -1;
            }
            steps = maxReachableIndex - i;
        }
    }
}

int main()
{
}