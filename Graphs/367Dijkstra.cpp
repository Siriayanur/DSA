#include<bits/stdc++.h>
#include<time.h>
using namespace std;

int main(){
    int n,e,src;
    cin >> n >> e;
    vector<pair<int,int>> graph[n + 1];
    for (int i = 0; i < e; i++)
    {
        int a, b,cost;
        cin >> a >> b >> cost;
        graph[a].push_back({b, cost});
        graph[b].push_back({a, cost});
    }
    cin >> src;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    vector<int> distance(n + 1, INT_MAX);

    //Distance of the source node fron itself is 0 
    distance[src] = 0;
    
    // vector<int> visited(n,0);

    pq.push(make_pair(0, src));
    int start = clock();
    while (!pq.empty())
    {
        pair<int,int> current = pq.top(); //{costOfGoingToCurrentNodeFromSrc,CurrentNode}
        pq.pop();
        int distToCurrentNode = current.first; // 0 + 4 --> 4
        int currentNode = current.second;

        for(auto i : graph[currentNode]){
            int adjNode = i.first;
            int adjNodeCost = i.second;
            if(/*!visited[adjNode]  &&*/ distance[adjNode] > distToCurrentNode + adjNodeCost){
                distance[adjNode] = distToCurrentNode + adjNodeCost;
                pq.push(make_pair(distance[adjNode], adjNode));
            }
        }
        // visited[src] = 1;
    }
    int end = clock();
    cout << "Time : " << end - start << endl;
    cout << "The shortest distances from the source node " << src << endl;
    for (int i = 0; i < n; i++){
        cout << distance[i] << " ";
    }
    cout << endl;
    return 0;
}
// 