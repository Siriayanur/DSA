#include <iostream>
using namespace std;

// s is the starting vertex

void dfsTraversal(int **edges, int n, int s, bool *visited)
{

    cout << s << endl;
    visited[s] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == s)
        {
            continue;
        }
        if (edges[s][i] == 1)
        {
            if (!visited[i])
            {
                dfsTraversal(edges, n, i, visited);
            }
        }
    }
}

void DFS_main(int **edges, int n)
{

    bool *visited = new bool[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfsTraversal(edges, n, i, visited);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    //Input the edges
    cout << "Enter the edges : " << endl;
    for (int i = 0; i < e; i++)
    {
        int st, en;
        cin >> st >> en;
        edges[st][en] = 1;
        edges[en][st] = 1;
    }

    DFS_main(edges, n);
}