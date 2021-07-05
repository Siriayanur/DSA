class Solution{
		
    int t[1001][1001];
    int solve(int cost[], int N, int W,int i)
    {
        if(i >= N)
        {
            if(W == 0)return 0;
        else
            return 999999999;
        }
        
          
         if(W <= 0)
            return 0;
        if(t[i][W] != -1)
            return t[i][W];
            
      
        if( cost[i] != -1 && W-i-1 >= 0)
        {
        return dp[i][W] = min(cost[i]+solve(cost,N,W-i-1,i),solve(cost,N,W,i+1));
        }
        else
        return dp[i][W] = solve(cost,N,W,i+1);
    }
    
    public:
    int minimumCost(int cost[], int N, int W)
    {
    // Your code goes here
        dp[N][W];
        memset(dp,-1,sizeof(dp));
        int ans = solve(cost,N,W,0);
        if(x == 999999999)
            return -1;
        return ans;
    }
};