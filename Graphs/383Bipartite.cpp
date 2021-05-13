#include <iostream>
using namespace std;

class Solution
{
public:
    bool helper(int curr, vector<int> adj[], int *col, int currentColor)
    {

        // cout << "Current : " << curr << " its color: " << col[curr] << endl;
        col[curr] = currentColor;

        // cout << "Changed Color of curr " <<  col[curr] << endl;
        // cout << "Neighbours :   their color" << endl;

        for (auto i : adj[curr])
        {

            // cout << i << " " <<  col[i] << endl;

            if (col[i] == -1)
            {

                if (!helper(i, adj, col, 1 - currentColor))
                {
                    // cout << "First IF curr : " << curr << " neighbour:  " << i << endl;
                    return false;
                }
            }

            else if (col[curr] == col[i])
            {
                // cout << "Second if with curr  "<< curr << " " << i << endl;
                // cout << col[curr] << " " << col[i] << endl;
                return false;
            }
        }
        return true;
    }

    bool isBipartite(int V, vector<int> adj[])
    {
        // Code here
        int col[V];
        for (int i = 0; i < V; i++)
            col[i] = -1;

        for (int i = 0; i < V; i++)
        {
            if (col[i] == -1)
            {
                if (!helper(i, adj, col, 0))
                    // cout << "executed" << endl;
                    return false;
            }
        }
        return true;
    }
};
