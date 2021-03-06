#include<bits/stdc++.h>
using namespace std;


bool solve(int a[],int n,int mid,int par){
	int time=0;
	int paratha = 0;
	for(int i=0;i<n;i++){
		time=a[i];
		int j = 2;
		while(time<=mid){
			paratha++;
			time = time + (a[i] * j);
			j++;
		}
		if(paratha>=par) return true;
	}
	return false;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int par;
		cin>>par;
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		int lb=0;
		int ub=1e8;
		int ans=0;
		while(lb<=ub){
			int mid=(lb+ub)/2;
			if(solve(a,n,mid,par)){
				ub = mid-1;
				ans = mid;
			}else{
				lb = mid+1;
			}
		}
		cout<< ans << endl;
	}
	return 0;
}