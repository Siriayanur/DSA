// abbcd

class Solution
{
public:
    int lcs(string a, string b)
    {
        int m = a.length(), n = b.length();
        int t[m + 1][n + 1];
        for (int i = 0; i <= m; i++)
            t[i][0] = 0;
        for (int i = 0; i <= n; i++)
            t[0][i] = 0;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i - 1] == b[j - 1] && i != j)
                    t[i][j] = 1 + t[i - 1][j - 1];
                else
                {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }
        return t[m][n];
    }
    int LongestRepeatingSubsequence(string str)
    {
        // Code here
        return lcs(str, str);
    }
};