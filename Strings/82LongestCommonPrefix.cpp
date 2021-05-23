#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    // solution 1:
    //Good explanation : https://www.youtube.com/watch?v=1YQmI7F9dJ0
    /*
        1.Keep the first word as reference  
        2. Traverse all characters of the first word and find if each character its equal to
        the character at the same position in all the strings;

        3.In case of a mismatch just return whatever prefixAnswer was obtained till now
        Also make sure to traverse the min(firstStringLength,jthStringLength)
    */
    string longestCommonPrefix(vector<string> &strs)
    {
        string longestCommonPrefix = "";
        for (int i = 0; i < strs[0].length(); i++) //1
        {
            for (int j = 1; j < strs.size(); j++) //2
            {
                if (i >= strs[j].length() || strs[0][i] != strs[j][i]) //3
                {
                    return longestCommonPrefix;
                }
            }
            longestCommonPrefix += strs[0][i];
        }
        return longestCommonPrefix;
    }

    //Solution 2
    //Here I am just checking each adjacent pair of words and updating the finalPrefixAns
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 1)
        {
            return strs[0];
        }

        //flower flow fleek flutter
        string prefix = ""; //"fl"

        for (int i = 0; i < strs.size() - 1; i++)
        {

            string temp = "";                                      // ""
            int idx = 0;                                           // 0
            int len = min(strs[i].length(), strs[i + 1].length()); // 5
            string curr = strs[i];                                 //fleek
            string next = strs[i + 1];                             // flutter

            while (curr[idx] == next[idx] && idx < len)
            {
                temp += curr[idx];
                idx++;
            }
            //If there is no matching characters between any adjacent set of strings
            // Then return ""
            if (temp == "")
            {
                return "";
            }
            if (prefix == "")
                prefix = temp;

            else if (temp.length() < prefix.length())
            {
                prefix = temp;
            }
        }
        return prefix;
    }
};