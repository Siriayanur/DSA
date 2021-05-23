#include <iostream>
using namespace std;

class Solution
{
public:
    int dp[1001][1001];
    //Function to find the length of longest common subsequence in two strings.
    int lcsRecursive(int x, int y, string s1, string s2)
    {
        // your code here
        if (x == 0 || y == 0)
        {
            return 0;
        }
        else
        {
            if (s1[x - 1] == s2[y - 1])
                return 1 + lcs(x - 1, y - 1, s1, s2);
            else
                return max(lcs(x - 1, y, s1, s2), lcs(x, y - 1, s1, s2));
        }
    }
    int helperMemoization(string x, string y, int m, int n)
    {
        if (m == 0 || n == 0)
        {
            return 0;
        }
        if (dp[m][n] != -1)
            return dp[m][n];
        if (x[m - 1] == y[n - 1])
        {
            return dp[m][n] = 1 + helperMemoization(x, y, m - 1, n - 1);
        }
        else
        {
            return dp[m][n] = max(helperMemoization(x, y, m - 1, n), helperMemoization(x, y, m, n - 1));
        }
    }
    int lcsMemoization(int x, int y, string s1, string s2)
    {
        // your code here
        memset(dp, -1, sizeof(dp));
        return helperMemoization(s1, s2, x, y);
    }
    int lcsDP(int x, int y, string s1, string s2)
    {
        int dp[x + 1][y + 1];
        // your code here
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i <= x; i++)
        {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= y; i++)
        {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= x; i++)
        {
            for (int j = 1; j <= y; j++)
            {

                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[x][y];
    }
};