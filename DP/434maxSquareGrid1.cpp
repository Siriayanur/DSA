#include<iostream>
#include<vector>
using namespace std;


class Solution{
    public:
        int maxSquare(int n, int m, vector<vector<int>> arr){
            // code here
            int dp[n][m];
            int ans = 0;
            for(int i = n-1; i >=0; i--){
                for(int j = m-1; j>= 0; j--){
                    if(i == n-1 || j == m-1){
                        dp[i][j] = arr[i][j];
                    }
                    
                    else{
                        if(arr[i][j] == 0){
                            dp[i][j] = 0;
                        }
                        else 
                            dp[i][j] = 1 + min(dp[i][j+1],min(dp[i+1][j],dp[i+1][j+1]));

                    }
                    ans = max(ans,dp[i][j]);
                }
            }
            return ans;
            
        }
};