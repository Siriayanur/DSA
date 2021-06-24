#include<iostream>
using namespace std;


long long paintFence(int n,int k){

    int mod = 1000000007;

    if(n == 0 || k == 0){
        return 0;
    }
    if(n == 1){
        return k;
    }
    long long same = (k * 1) % mod;
    long long diff = (k * (k - 1)) % mod;
    long long total = (same + diff) % mod;
    for (int i = 3; i <= n;i++){
        same = (diff * 1) % mod;
        diff = (total * (k - 1)) % mod;
        total = (same + diff) % mod;
    }
    return (total % mod);
}
int main(){
    int n, k;
    cin >> n >> k;
    cout << paintFence(n, k) << endl;
    return 0;
}