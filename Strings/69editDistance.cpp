#include <iostream>
using namespace std;

/***
 * Initialisation
 * 0 1 2 3 4 5 
 * 1
 * 2
 * 3
 * 
 * 
 * 
 */

//o(max(3^n,3^m)+mod(m-n)) ~~~ exponential (3^m + 3^n)
int editDistanceRecursive(string s1, string s2, int i, int j)
{
    if (i == 0 || j == 0)
    {
        return i == 0 ? j : i;
    }
    else if (s1[i - 1] == s2[j - 1])
    {
        return editDistanceRecursive(s1, s2, i - 1, j - 1);
    }
    else
    {
        int x = 1 + editDistanceRecursive(s1, s2, i, j - 1); // Insertion
        int y = 1 + editDistanceRecursive(s1, s2, i - 1, j); //Deletion
        int z = 1 + editDistanceRecursive(s1, s2, i - 1, j - 1);
        return min(x, min(y, z));
    }
}

//optimised BottomUp DP -- 0(m*n) Time and space
class Solution
{
public:
    int t[101][101];
    int editDistanceDP(string s1, string s2, int m, int n)
    {
        int dp[m + 1][n + 1];

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0)
                    dp[i][j] = j;

                else if (j == 0)
                    dp[i][j] = i;

                else
                {
                    if (s1[i - 1] == s2[j - 1])
                    {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    else
                    {
                        dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                    }
                }
            }
        }
        return dp[m][n];
    }
    int editDistance(string s1, string s2)
    {
        // Code here
        //initialisation of t[][]

        return editDistanceDP(s1, s2, s1.length(), s2.length());
    }
};

int main()
{
    string s2 = "gesek";
    string s1 = "geek";
    cout << editDistanceRecursive(s1, s2, s1.length(), s2.length()) << endl;
    return 0;
}