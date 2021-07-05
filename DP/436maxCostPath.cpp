#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
        int maximumPath(int n, vector<vector<int>> a)
        {
            // code here
            for(int i = 1;i < n; i++){
                for(int j = 0; j < n; j++){
                    int x = (j == 0 ? 0 : a[i-1][j-1]);
                    int y = a[i-1][j];
                    int z = (j == n-1 ? 0 : a[i-1][j+1]);
                    a[i][j] = a[i][j] + max(x,max(y,z));
                }
            }
            int result = INT_MIN;
            for(int i = 0; i < n;i ++){
                result = max(result,a[n-1][i]);
            }
            return result;
            
        }
};