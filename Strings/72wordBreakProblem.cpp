#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/**
 * good explanation : 
 * https://www.youtube.com/watch?v=2NaaM_z_Jig&t=146s
 * 
 * eg:
 * pepc|oding
 *    i
 * 0|0|1|
 * 
*/
bool helper(unordered_map<string, int> &map, string s)
{
    if (s.length() == 0)
    {
        return true;
    }
    string current = "";
    for (int i = 0; i < s.length(); i++)
    {
        current += s[i];
        if (map.count(current) > 0)
        {
            return helper(map, s.substr(i + 1));
        }
    }
    return false;
}

int wordBreakRecursion(string s, vector<string> &dict)
{
    //code here

    unordered_map<string, int> map;
    for (int i = 0; i < dict.size(); i++)
    {
        map[dict[i]]++;
    }

    return helper(map, s);
}
int wordBreakDP(string A, vector<string> &B)
{
    int dp[A.length()] = {0};
    unordered_map<string, int> map;
    for (int i = 0; i < B.size(); i++)
    {
        map[B[i]]++;
    }
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            string current = A.substr(j, i - j + 1);
            if (map[current] > 0)
            {
                if (j > 0)
                {
                    dp[i] += dp[j - 1];
                }
                else
                {
                    dp[i] += 1;
                }
            }
        }
    }
    return dp[A.size() - 1] > 0;
}
int main()
{
}