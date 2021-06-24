#include<bits/stdc++.h>
using namespace std;

bool dfs(int src,int currentLength,int k,int visited[],vector<pair<int,int>> graph[]){
    if(currentLength >= k)
        return true;

    visited[src] = 1;
    for(auto i : graph[src]){
        if(!visited[i.first]){
            if(dfs(i.first, currentLength + i.second, k, visited, graph))
                return true;
        }
    }
    visited[src] = 0;
    return false;
}

bool pathMoreThanK(int v, int e, int k, int *a) 
{ 
       //  Code Here
       if(k <= 0)
            return true;

       vector<pair<int, int>> graph[v];
       for (int i = 0; i < 3 * e; i = i + 3){
           graph[a[i]].push_back({a[i + 1], a[i + 2]});
           graph[a[i + 1]].push_back({a[i], a[i + 2]});
       }
       int visited[v] = {0};
       return dfs(0, 0, k, visited, graph);
}