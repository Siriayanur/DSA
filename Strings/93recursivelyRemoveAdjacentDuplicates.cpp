#include <iostream>
using namespace std;

//Recursive
string removeConsecutiveCharacter(string s)
{
    // code here.
    if (s.size() == 0)
        return "";

    char ch = s[0];
    string ans = removeConsecutiveCharacter(s.substr(1));

    if (ch == ans[0])
        return ans;
    return ch + ans;
}

//Iterative
string removeConsecutiveCharacter(string s)
{
    // code here.
    string ans = "";
    int n = s.length();

    int i = 0, j = 1;
    while (i < n)
    {
        if (j < n)
        {
            while (s[i] == s[j])
            {
                j++;
            }
        }
        ans = ans + s[i];
        i = j;
        j = i + 1;
    }
    return ans;
}