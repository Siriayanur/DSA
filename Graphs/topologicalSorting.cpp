#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void topo(int current, vector<int> adj[], bool visited[], stack<int> &st)
    {

        vector<int>::iterator it;
        visited[current] = true;
        for (it = adj[current].begin(); it != adj[current].end(); it++)
        {
            if (!visited[*it])
            {
                topo(*it, adj, visited, st);
            }
        }
        st.push(current);
    }

    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here
        vector<int> result;
        bool visited[V];
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                topo(i, adj, visited, st);
            }
        }
        while (!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};