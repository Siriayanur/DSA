#include <iostream>
using namespace std;
#include <unordered_map>

class Solution
{
public:
    string findSubString(string str)
    {
        // Your code goes here
        unordered_map<char, int> map;
        for (int i = 0; i < str.length(); i++)
        {
            map[str[i]] = -1;
        }
        int s = 0, e = 0;
        int resLen = INT_MAX, finalStart = 0;
        int count = 0;
        int len = map.size();

        while (s <= e && e <= str.length() - 1)
        {
            if (map[str[e]] == -1)
            {
                map[str[e]] = 1;
                count++;
            }
            else
            {
                map[str[e]]++;
            }
            if (count == len)
            {
                while (s <= e && map[str[s]] > 1)
                {
                    map[str[s]]--;
                    s++;
                }
                if (resLen > e - s + 1)
                {
                    resLen = e - s + 1;
                    finalStart = s;
                }
                map[str[s++]] = -1;
                count--;
            }
            e++;
        }
        return str.substr(finalStart, resLen);
    }
};
