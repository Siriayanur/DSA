class Solution {
  public:
    long long int countBT(int h) { 
        // code here
        if(h == 0 || h == 1){
            return 1;
        }
        
        long long int mod = 1000000007;
        long long int dp[h+1];
        dp[0] = dp[1] = 1;
        
        
        for(int i = 2; i <= h; i++){
            dp[i] = ((2 * dp[i-1] * dp[i-2])%mod + (dp[i-1] * dp[i-1])%mod)%mod;
        }
        return dp[h];
    }
};