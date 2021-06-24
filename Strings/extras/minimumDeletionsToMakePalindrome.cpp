#include <iostream>
using namespace std;

class Solution
{
public:
    int lcs(string s, string r)
    {
        int m = s.length(), n = r.length();
        int t[m + 1][n + 1];
        for (int i = 0; i <= m; i++)
            t[i][0] = 0;
        for (int i = 0; i <= n; i++)
            t[0][i] = 0;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == r[j - 1])
                {
                    t[i][j] = 1 + t[i - 1][j - 1];
                }
                else
                {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }
        return t[m][n];
    }

    int minimumNumberOfDeletions(string s)
    {
        // code here
        string r = s;
        reverse(s.begin(), s.end());
        return s.length() - lcs(s, r);
    }
};