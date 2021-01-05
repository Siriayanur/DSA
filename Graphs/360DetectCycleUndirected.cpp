#include <bits/stdc++.h>
using namespace std;

bool isCyclicHelper(vector<int> graph[], bool *visited, int currentNode, int parent)
{

    visited[currentNode] = true;

    for (int i = 0; i < graph[currentNode].size(); i++)
    {
        if (!visited[graph[currentNode][i]])
        {
            if (isCyclicHelper(graph, visited, graph[currentNode][i], currentNode))
            {
                return true;
            }
        }
        else if (graph[currentNode][i] != parent || graph[currentNode][i] == currentNode)
        {
            return true;
        }
    }
    return false;
}

bool isCyclic(vector<int> graph[], int v)
{
    // Your code here
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < v; i++)
    {
        if (!visited[i] && isCyclicHelper(graph, visited, i, -1))
        {
            return true;
        }
    }
    return false;
}