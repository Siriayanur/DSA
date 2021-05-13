#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*  Function to find the number of strongly connected components
    *   using Kosaraju's algorithm
    *   V: number of vertices
    *   adj[]: array of vectors to represent graph
    */

    void dfs(int curr, bool visited[], vector<int> adj[], stack<int> &st)
    {
        visited[curr] = true;

        vector<int>::iterator it;
        for (it = adj[curr].begin(); it != adj[curr].end(); it++)
        {

            if (!visited[*it])
            {

                dfs(*it, visited, adj, st);
            }
        }

        st.push(curr);
    }

    void revDfs(int curr, bool visited[], vector<int> rev[])
    {

        visited[curr] = true;

        vector<int>::iterator it;
        for (it = rev[curr].begin(); it != rev[curr].end(); it++)
        {
            if (!visited[*it])
            {
                revDfs(*it, visited, rev);
            }
        }
    }

    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        stack<int> st;
        int count = 0;

        bool visited[V] = {false};
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, adj, st);
            }
        }

        vector<int> rev[V];

        for (int i = 0; i < V; i++)
        {
            for (auto j : adj[i])
            {
                rev[j].push_back(i);
            }
        }

        memset(visited, false, sizeof(visited));

        while (!st.empty())
        {
            int x = st.top();
            st.pop();
            if (!visited[x])
            {
                revDfs(x, visited, rev);
                count++;
            }
        }
        return count;
    }
};