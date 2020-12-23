#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[abs(nums[i])] >= 0)
            {
                nums[abs(nums[i])] = -1 * nums[abs(nums[i])];
            }
            else
            {
                ans = abs(nums[i]);
            }
        }
        return ans;
    }
};