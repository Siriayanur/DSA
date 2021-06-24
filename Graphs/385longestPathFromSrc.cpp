#include<bits/stdc++.h>
using namespace std;

//topological ordering
void topoSort(stack<int> &topo,vector<vector<pair<int,int>>> &graph,vector<int> visited,int current){
    visited[current] = 1;
    vector<int> it;
    pair<int, int> p;
    for (auto it : graph[current])
    {
        if(!visited[it.first])
            topoSort(topo, graph, visited, i);
    }
    topo.push(current);
}

int main(){
    int n, e;
    cin >> n >> e;

    int src;
    cin >> src;

    //adjacency list
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < e; i++){
        int s,e,w;
        cin >> s >> e >> w;
        graph[s].push_back({e, w});
    }
    stack<int> topo;
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++){
        if(!visited[i]){
            topoSort(topo,graph, visited,i);
        }
    }

    vector<int> distance(n);
    for (int i = 0; i < n; i++){
        distance[i] = INT_MIN;
    }
    distance[0] = 0;
    while(!topo.empty()){                                                           
        int top = topo.top();
        if(distance[top] != INT_MIN ){
            for (auto it : graph[top]){
                int st = distance[it.first];
                int w = it.second;
                int en = distance[top];
                if(en + w > st){
                    distance[it.first] = en + w;
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        if(i != src and distance[i] != INT_MIN){
            cout << src << " " << i << " " << distance[i] << endl;
        }
    }
    return 0;
}