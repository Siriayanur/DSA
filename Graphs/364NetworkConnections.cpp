#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited)
    {
        visited[node] = true;

        for (int i = 0; i < graph[node].size(); i++)
            if (!visited[graph[node][i]])
                dfs(graph[node][i], graph, visited);
    }

    int makeConnected(int n, vector<vector<int>> &connections)
    {

        // total edges count
        int edge_count = connections.size();

        // if total edge count < n-1 then conenction not possible
        if (edge_count < n - 1)
            return -1;

        // graph adjacency list
        vector<vector<int>> graph(n);

        // populate graph adjacency list
        for (int i = 0; i < connections.size(); i++)
        {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }

        // number of connected componenets
        int connectedNetworks = 0;

        // track visited nodes
        vector<bool> visited(n, false);

        // run DFS on unvisited nodes and count connected components
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, graph, visited);
                connectedNetworks++;
            }
        }

        // minimum number of connection extraction
        return connectedNetworks - 1;
    }
};