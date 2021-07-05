#include<iostream>
using namespace std;

int maxSumIS(int a[], int n)  
{  
	    // Your code goes here
	    if(n == 0) return 0;
       
       int dp[n] = {-1};
       
       dp[0] = a[0];
       
       //10 22 9 33
       int result = dp[0];
       
       for(int i = 1; i < n; i++){
           int currentMax = 0;
           for(int j = 0;j < i; j++){
               if(a[i] > a[j]){
                   currentMax = max(currentMax,dp[j]);
               }
           }
           dp[i] = currentMax+a[i];
           result = max(dp[i],result);
       }
    
        return result;
}  