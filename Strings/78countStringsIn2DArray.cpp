#include <iostream>
using namespace std;

#define m 6
#define n 6

int solve(int i, int j, char input[m][n], string s, int len, int idx)
{
    int found = 0;
    if (i >= 0 && j >= 0 && i < m && j < n && input[i][j] == s[idx])
    {
        char temp = input[i][j];
        input[i][j] = '0';

        idx++;
        if (idx == len)
            found = 1;
        else
        {
            found += solve(i + 1, j, input, s, len, idx);
            found += solve(i - 1, j, input, s, len, idx);
            found += solve(i, j + 1, input, s, len, idx);
            found += solve(i, j - 1, input, s, len, idx);
        }
        input[i][j] = temp;
    }
    return found;
}

int main()
{

    char input[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> input[i][j];
        }
    }
    string s;
    cin >> s;
    int len = s.length();

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans += solve(i, j, input, s, len, 0);
        }
    }
    cout << ans << endl;
}