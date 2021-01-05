#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isCyclicHelper(vector<int> adj[], int v, bool *visited, bool *recStack)
{
    if (visited[v] == false)
    {

        visited[v] = true;
        recStack[v] = true;
    }
    vector<int>::iterator p;
    for (p = adj[v].begin(); p != adj[v].end(); p++)
    {
        if (!visited[*p] && isCyclicHelper(adj, *p, visited, recStack))
        {
            return true;
        }
        if (recStack[*p])
        {
            return true;
        }
    }
    //Pop the node from the recStack
    recStack[v] = false;
    return false;
}

bool isCyclic(int v, vector<int> adj[])
{
    // Your code here
    bool *visited = new bool[v];
    bool *recStack = new bool[v];

    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (isCyclicHelper(adj, v, visited, recStack))
        {
            return true;
        }
    }
    return false;
}

int main()
{
}