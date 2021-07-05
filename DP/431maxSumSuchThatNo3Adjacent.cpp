#include<iostream>
using namespace std;

int solve(int arr[],int n ){
    int dp[n ] = {0};
    dp[0] = arr[0];
    int result = dp[0];
    for (int i = 0; i < n; i++){
        if(i%3 == 2){
            dp[i] = arr[i];
            continue;
        }
        int currentMaxSum = 0;
        for (int j = 0; j < i; j++)
        {
            currentMaxSum = max(currentMaxSum, dp[j]);
        }
        dp[i] = arr[i] + currentMaxSum;
    }
    for (int i = 0; i < n; i++)
    {
        if(result < dp[i])
            result = dp[i];
    }
    return result;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << solve(arr, n) << endl;
    return 0;
}
/**
 * 
 * g++ 431maxSumSuchThatNo3Adjacent.cpp 
 >> DP$ ./a.out 
5 
3000    
2000
1000
3
10
5013
>> DP$ ./a.out 
5
100
1000
100
1000
1
2101
>> DP$ ./a.out 
4
1 1 1 1 
3
*/
