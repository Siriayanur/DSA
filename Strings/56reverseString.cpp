#include <iostream>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        if (s.size() == 1 || s.size() == 0)
        {
            return;
        }
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            int temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
};