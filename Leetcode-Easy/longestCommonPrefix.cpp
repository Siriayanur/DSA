#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> strs)
{
    string longestCommonPrefix = "";
    for (int i = 0; i < strs[0].length(); i++)
    {
        for (int j = 0; j < strs.size(); j++)
        {
            if (i >= strs[j].length() || strs[0][i] != strs[j][i])
            {
                return longestCommonPrefix;
            }
        }
        longestCommonPrefix += strs[0][i];
    }
    return longestCommonPrefix;
}
