#include <iostream>
using namespace std;

class Solution
{
public:
    string reverseOnlyLetters(string S)
    {
        int i = 0;
        int j = S.length() - 1;
        while (i < j)
        {
            // 97 to 122 or 65 to 90
            while (i < j && !isalpha(S[i]))
            {
                i++;
            }
            while (i < j && !isalpha(S[j]))
            {
                j--;
            }
            char c = S[i];
            S[i++] = S[j];
            S[j--] = c;
        }
        return S;
    }
};