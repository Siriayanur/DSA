#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,e,src,dest;
    cin >> n >> e;
    vector<pair<int, int>> graph[n+1];
    for (int i = 0; i < e; i++)
    {
        int a, b, cost;
        cin >> a >> b;
        graph[a].push_back(make_pair(b, 0));
        //reversing the edge
        graph[b].push_back(make_pair(a, 1));
    }
    cin >> src >> dest;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(n + 1, INT_MAX);

    //Distance of the source node fron itself is 0 
    distance[src] = 0;
    
    pq.push(make_pair(0, src));

    while (!pq.empty())
    {
        pair<int,int> current = pq.top(); //{costOfGoingToCurrentNodeFromSrc,CurrentNode}
        pq.pop();
        int distToCurrentNode = current.first; 
        int currentNode = current.second;

        for(auto i : graph[currentNode]){
            int adjNode = i.first;
            int adjNodeCost = i.second;
            if( distance[adjNode] > distToCurrentNode + adjNodeCost){
                distance[adjNode] = distToCurrentNode + adjNodeCost;
                pq.push(make_pair(distance[adjNode], adjNode));
            }
        }
        
    }
    if(distance[dest] == INT_MAX)
        cout << "INFINITY" << endl;
    else
        cout << "The minimum edges to reverse : " << distance[dest] << endl;

    return 0;
}
/**
Graphs$ ./a.out 
7 7
0 1
2 1
2 3
6 3
6 4
4 5
5 0
0
6
The minimum edges to reverse : 2
Graphs$ ./a.out 
7 7 
1 0
2 1
3 2
6 3
6 4
4 5
5 0
0 6
The minimum edges to reverse : 3
 * 
 * 
 * 
 * 
 * 
*/