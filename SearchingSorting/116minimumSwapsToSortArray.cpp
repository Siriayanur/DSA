#include <bits/stdc++.h>

using namespace std;

void mySwap(vector<int> &nums, int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

int minSwaps(vector<int> &nums)
{
    // Code here
    int n = nums.size();
    vector<int> temp = nums;

    sort(temp.begin(), temp.end());
    unordered_map<int, int> m;
    int swaps = 0;

    for (int i = 0; i < n; i++)
    {
        m[nums[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {

        if (nums[i] != temp[i])
        {
            swaps++;
            int original = nums[i];

            mySwap(nums, i, m[temp[i]]);

            m[original] = m[temp[i]];
            m[temp[i]] = i;
        }
    }
    return swaps;
}
int main()
{
}