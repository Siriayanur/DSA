#include<iostream>
using namespace std;

class Solution
{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    
	    int ans = 0;
	    int currentSum = 0;
	    for(int i = 0; i < S.length(); i++){
	        int val = 0;
	        
	        if(S[i] == '0'){
	            val = 1;
	        }
	        if(S[i] == '1'){
	            val = -1;
	        }
	        if(currentSum > 0){
	            currentSum += val;
	        }
	        else{
	            currentSum = val;   
	        }
	        if(currentSum > ans){
	            ans = currentSum;
	        }
	    }
	    
	    if(ans == 0){
	        ans = -1;
	    }
	    return ans;
	}
};