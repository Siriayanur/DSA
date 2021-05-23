/**
 * 0011
 * 
 * 
 * Give a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // o(n) time o(n)space
    int countBinarySubstrings(string s)
    {
        vector<int> store(s.size());
        int index = 0;
        store[0] = 1;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != s[i - 1])
            {
                index++;
                store[index] = 1;
            }
            else
            {
                store[index]++;
            }
        }
        int ans = 0;

        for (int i = 1; i <= index; i++)
        {
            ans += min(store[i], store[i - 1]);
        }
        return ans;
    }
    //O(N) 0(1)
    int countBinarySubstrings(string s)
    {

        int prevCount = 0;
        int currentCount = 1;
        int ans = 0;

        for (int i = 1; i < s.length(); i++)
        {
            if (s[i - 1] != s[i])
            {
                ans += min(prevCount, currentCount);
                prevCount = currentCount;
                currentCount = 1;
            }
            else
            {
                currentCount += 1;
            }
        }
        ans += min(prevCount, currentCount);
        return ans;
    }
};

int main()
{
    string input;
    cin >> input;
    Solution obj = Solution();
    cout << obj.countBinarySubstrings(input) << endl;
    return 0;
}