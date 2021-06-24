#include<bits/stdc++.h>
using namespace std;

int t[10000];

//Recursive approach
int solve(int n, int x, int y, int z)
{

    if(n == 0)
        return 0;
    int a = INT_MIN, b = INT_MIN, c = INT_MIN,res= INT_MIN;
    if(n >= x)
        a = solve(n - x, x, y, z);
    if(n >= y)
        b = solve(n - y, x, y, z);
    if(n >= z)
        c = solve(n - z, x, y, z);
    res = 1 + max(a, max(b, c));
    return res;
}

//Memoization
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int t[10001];
    int solve2(int n, int x, int y, int z){
    
        if(n == 0)
            return 0;
            
        if(t[n] != -1)
            return t[n];
            
        int a = INT_MIN, b = INT_MIN, c = INT_MIN,res;
        
        if(n >= x)
            a = solve2(n - x, x, y, z);
        if(n >= y)
            b = solve2(n - y, x, y, z);
        if(n >= z)
            c = solve2(n - z, x, y, z);
        
        t[n] = 1 + max(a,max(b,c));
        return t[n];
    }
    
   

    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        memset(t, -1, sizeof(t));
        int res = solve2(n, x, y, z);
        if(res <= 0)
            return 0;
        return res;
    }
};

//Main for Recursive

int main(){

    int res = solve(5, 5, 3, 2);
    if( res <= 0)
        cout << "0" << endl;
    cout << res << endl;
    return  0;
}