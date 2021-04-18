#include <bits/stdc++.h>
using namespace std;

int findMaxLen(string s)
{
    int maxLength = 0;
    int left = 0, right = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            left++;

        if (s[i] == ')')
            right++;

        if (left == right)
            maxLength = max(maxLength, right * 2);

        if (right > left)
        {
            left = right = 0;
        }
    }
    left = right = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == '(')
            left++;

        if (s[i] == ')')
            right++;

        if (left == right)
            maxLength = max(maxLength, left * 2);

        if (left > right)
            left = right = 0;
    }
    return maxLength;
}