#include <iostream>
using namespace std;

// O(W*N) space
int knapSack(int N, int W, int val[], int wt[])
{
    // code here
    int t[N + 1][W + 1];
    memset(t, -1, sizeof(t));

    for (int i = 0; i < N + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[i][j - wt[i - 1]], t[i - 1][j]);
            }
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[N][W];
}

// O(W) space
int knapSack2(int N, int W, int val[], int wt[])
{
    // code here
    int dp[W + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (j >= wt[i])
            {
                dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);
            }
        }
    }
    return dp[W];
}