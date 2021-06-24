#include<bits/stdc++.h>
using namespace std;
vector<int> inTime;
vector<int> outTime;
int timer=1;

void resize(int n){
    inTime.resize(n+1); //n+1  or n
    outTime.resize(n+1);
}

void dfs(int current,int parent,vector<int> graph[]){
    inTime[current] = timer++;
    for(auto i : graph[current]){
        if(i != parent){
            dfs(i, current, graph);
        }
    }
    outTime[current] = timer++;
}

int check(int x,int y){
    if(inTime[x] < inTime[y] && outTime[x] > outTime[y])
        return true;
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    timer = 1;
    int n;
    resize(n);
    vector<int> graph[n + 1];
    for (int i = 0; i < n-1;i ++){
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    dfs(1, 0, graph);
    int q;
    cin >> q;
    while(q--){
        int type, x, y;
        cin >> type >>x >> y;
        if(type == 0){
            if(check(x,y)){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }else if(type == 1){
            if(check(y,x)){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
}