#include<bits/stdc++.h>
using namespace std;

int t[101][101][101];
int lcs(string& a,string &b,string& c,int n1,int n2,int n3){
    if(n1 == 0 || n2 == 0 || n3==0){
        return 0;
    }
    if(t[n1][n2][n3] != -1)
        return t[n1][n2][n3];
    
    if(a[n1-1] == b[n2-1] && b[n2-1] == c[n3-1]){
        return t[n1][n2][n3] = 1+ lcs(a,b,c,n1-1,n2-1,n3-1);
    }else{
        return t[n1][n2][n3] = max(lcs(a,b,c,n1,n2-1,n3),max(lcs(a,b,c,n1-1,n2,n3),lcs(a,b,c,n1,n2,n3-1)));
    }
}


int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    memset(t,-1,sizeof(t));
    return lcs(A,B,C,n1,n2,n3);
}