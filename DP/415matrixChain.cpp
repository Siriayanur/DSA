#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int t[101][101];
    int solve(int arr[],int i,int j){
        if(i >= j){
            return 0;
        }
        if(t[i][j] != -1)
            return t[i][j];
        int minRes = INT_MAX;
        for(int k = i; k <= j-1;k ++){
            int res = (arr[i-1] * arr[k] * arr[j]) + solve(arr,i,k) + solve(arr,k+1,j) ;
        
            minRes = min(res,minRes);
        }
        return t[i][j] = minRes;
    }


    int matrixMultiplication(int n, int arr[])
    {
        // code here
        memset(t,-1,sizeof(t));
        return solve(arr,1,n-1);
    }
};