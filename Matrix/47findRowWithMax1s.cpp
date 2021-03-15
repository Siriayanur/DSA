#include <iostream>
using namespace std;

class Solution
{
public:
    //O(nlogm)
    // logm at every row for n rows
    int rowWithMax1s_mine(vector<vector<int>> arr, int n, int m)
    {
        // code here
        int maxCount = 0;
        int maxIndex = -1;
        for (int i = 0; i < arr.size(); i++)
        {

            int count = 0;

            count = upper_bound(arr[i].begin(), arr[i].end(), 1) - upper_bound(arr[i].begin(), arr[i].end(), 0);
            if (count > maxCount)
            {
                maxCount = count;
                maxIndex = i;
            }
        }
        return maxIndex;
    }

    //o(m+n)
    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        int res_index = -1;
        int j = m - 1;

        for (int i = 0; i < n; i++)
        {
            while (j >= 0)
            {
                if (arr[i][j] == 1)
                {
                    j--;

                    res_index = i;
                }
                else
                {
                    break;
                }
            }
        }

        return res_index;
    }
};