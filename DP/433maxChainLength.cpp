
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};
int comparator(struct val a,struct val b){
    return a.second < b.second;
}

int maxChainLen(struct val p[],int n)
{
    
    if(n == 0)
        return 0;
    //Your code herei
    sort(p,p+n,comparator);
    for (int i = 0; i < n; i++){
        cout << p[i].first << " " << p[i].second << endl;
    }
    int dp[n];
    
    dp[0] = 1;
    int result = dp[0];
    
    for(int i = 0; i < n; i++){
        int currentMaxResult = 0;
        for(int j = 0; j < i; j++){
            if(p[j].second < p[i].first){
                currentMaxResult = max(currentMaxResult,dp[j]);
            }
        }
        dp[i] = currentMaxResult + 1;
    }
    for(int i = 0; i < n; i++){
        result = max(result,dp[i]);
    }
    return result;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}