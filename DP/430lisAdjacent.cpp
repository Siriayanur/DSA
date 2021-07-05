#include<iostream>
using namespace std;



class Solution{
public:
    int longestSubsequence(int n, int a[])
    {
        // code here
        int dp[n] = {0};
        dp[0] = 1;
        int result = dp[0];
        for(int i = 0; i < n; i++){
            int currentMax = 0;
            for(int j = 0; j < i; j++){
                if(abs(a[j]-a[i]) == 1){
                    currentMax = max(currentMax,dp[j]);
                }
            }
            dp[i] = 1 + currentMax;
        }
        for(int i = 0; i < n; i++){
            if(dp[i] > result)
                result = dp[i];
        }
        return result;
    }
};