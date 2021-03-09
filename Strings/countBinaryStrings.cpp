#include <iostream>
using namespace std;

/*

Give a string s, count the number of non-empty (contiguous) substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.
*/
int countBinarySubstrings(string s)
{
    int res = 0;
    for (int i = 0; i < s.size() - 1; ++i)
    {
        if (s[i] != s[i + 1])
        {
            int left = i, right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[i] && s[right] == s[i + 1])
            {
                --left, ++right;
                ++res;
            }
            i = right - 2;
        }
    }
    return res;
}