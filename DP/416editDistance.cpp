#include <iostream>
using namespace std;

//Memoized code solution
int editDistance_mem(int **output, string s, string t)
{

    int m = s.size();
    int n = t.size();

    if (m == 0 && n == 0)
    {
        return 0;
    }
    if (m == 0)
    {
        return n;
    }
    if (n == 0)
    {
        return m;
    }

    if (output[m][n] != -1)
    {
        return output[m][n];
    }
    int res;
    if (s[0] == t[0])
    {
        res = editDistance_mem(output, s.substr(1), t.substr(1));
    }
    else
    {
        int a = 1 + editDistance_mem(output, s.substr(1), t);
        int b = 1 + editDistance_mem(output, s, t.substr(1));
        int c = 1 + editDistance_mem(output, s.substr(1), t.substr(1));
        res = min(a, min(b, c));
    }

    //Store the result
    output[m][n] = res;
    return res;
}

int editDistance(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();

    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
    }
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            output[i][j] = -1;
        }
    }

    return editDistance_mem(output, s1, s2);
}
