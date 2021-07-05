#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       if(n == 0) return 0;
       
       int dp[n] = {-1};
       
       dp[0] = 1;
       
       //10 22 9 33
       int result = dp[0];
       
       for(int i = 1; i < n; i++){
           int currentMax = 0;
           for(int j = 0;j < i; j++){
               if(a[i] > a[j]){
                   currentMax = max(currentMax,dp[j]);
               }
           }
           dp[i] = currentMax+1;
           result = max(dp[i],result);
       }
    
        return result;
    }
};