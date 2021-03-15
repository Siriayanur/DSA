#include <iostream>
#include <unordered_map>

using namespace std;
#define MAX_CHAR 26

bool areIsomorphic(string str1, string str2)
{

    // Your code here
    char record[MAX_CHAR] = {0};
    if (str1.length() != str2.length())
    {
        return false;
    }

    unordered_map<char, char> map;
    for (int i = 0; i < str1.length(); i++)
    {

        if (map.find(str1[i]) != map.end())
        {

            if (str2[i] != map[str1[i]])
                return false;
        }
        else
        {

            if (record[str2[i] - 'a'] == 1)
            {
                return false;
            }
            map[str1[i]] = str2[i];
            record[str2[i] - 'a'] = 1;
        }
    }
    return true;
}