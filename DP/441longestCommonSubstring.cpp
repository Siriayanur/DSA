class Solution{
    public:
    int solve(string& x,string& y,int n,int m){
        int t[1001][1001];
        for(int i = 0; i <= n; i++){
            t[n][i] = 0;
        }
        for(int i = 0; i <= m; i++){
            t[i][m] = 0;
        }
        
        int result= 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <=m ;j++){
                if(x[i-1] == y[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                    result = max(result,t[i][j]);
                }else{
                    t[i][j] = 0;
                }
            }
        }
        return result;
        
    }
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        if(m == 0 && n == 0)
            return 0;
        
        return solve(s1,s2,n,m);
    }
};
