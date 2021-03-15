#include <iostream>
using namespace std;

int minFlips(string S)
{
    // your code here
    int pattern1 = 0; // 0101010101
    int pattern2 = 0;

    int i = 0, j = 1;
    while (i < S.length() || j < S.length())
    {
        if (S[i] != '0' && i < S.length())
            pattern1++;
        if (S[j] != '1' && j < S.length())
            pattern1++;

        i += 2;
        j += 2;
    }

    i = 1;
    j = 0;

    while (i < S.length() || j < S.length())
    {
        if (S[i] != '0' && i < S.length())
            pattern2++;
        if (S[j] != '1' && j < S.length())
            pattern2++;
        i += 2;
        j += 2;
    }

    return min(pattern1, pattern2);
}