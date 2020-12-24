
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        int min = INT_MAX;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < min)
            {
                min = prices[i];
            }
            else
            {
                profit = max(profit, prices[i] - min);
            }
        }
        return profit;
    }
};