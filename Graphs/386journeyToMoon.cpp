#include <bits/stdc++.h>

using namespace std;

void dfs(vector<long> graph[], vector<long>& visited,long current,long& count){
    visited[current] = 1;
    count++;
    for(auto i : graph[current]){
        if(!visited[i]){
            dfs(graph,visited,i,count);
        }
    }
}

int main(){
    long v,p;
    cin >> v >> p;
    vector<long> graph[v];
    vector<long> visited(v,0);
    for(long i = 0; i  < p; i++){
        long s,e;
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    
    //dfs
    vector<long>result;
    for(long i = 0; i < v; i++){
        if(!visited[i]){
            long count = 0;
            dfs(graph,visited,i,count);
            result.push_back(count);
        }    
    }
    long total = (v * (v-1))/2;
    for(long i = 0; i < result.size(); i++){
        long x = (result[i] * (result[i]-1))/2;
        total -= x;
    }
    cout << total;
}