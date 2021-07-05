#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int getMinValNode(vector<int>& distance,vector<int>& visited){
    int minval = INT_MAX;
    int minnode = 0;
    for (int i = 0; i < distance.size(); i++){
        if(distance[i] < minval && !visited[i]){
            minval = distance[i];
            minnode = i;
        }
    }
    return minnode;
}

void prims(int n,vector<int>& visited,vector<int>&parent,vector<int>& distance,vector<pair<int,int>> graph[]){
    parent[0] = -1;
    distance[0] = 0;
    for (int i = 0; i < n;i++){
        int src = getMinValNode(distance,visited);
        visited[src] = 1;
        for(auto k : graph[src]){
            if(!visited[k.first] && (distance[k.first] > k.second)){
                distance[k.first] =  k.second;
                parent[k.first] = src;
            }
        }
    }
    cout << "From\t\tParent\t\tCost" << endl;
    for (int i = 0; i < parent.size(); i++)
    {
        cout << i << "\t\t" << parent[i] << "\t\t" << distance[i] << endl;
    }
}


int main(){
    int n, e;
    cin >> n >> e;

    vector<pair<int, int>> graph[n];
    vector<int> distance(n,INT_MAX);
    vector<int> visited(n, 0);
    vector<int> parent(n, 0);


    for (int i = 0; i < e; i++)
    {
        int s, en,cost;
        cin >> s >> en >> cost;
        graph[s].push_back(make_pair(en, cost));
        graph[en].push_back(make_pair(s, cost));
        parent[i] = i;
    }
    //Graph is populated
    
    prims(n,visited,parent,distance,graph);
}
/*
Graphs$ ./a.out 
4
5
0 1 3
0 2 1
1 2 2
2 3 5
1 3 4
From            Parent          Cost
0               -1              0
1               2               2
2               0               1
3               1               4

*/