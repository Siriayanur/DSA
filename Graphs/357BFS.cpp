#include <iostream>
using namespace std;
#include <queue>

void bfsTraversal(int **edges, int n, int s, bool *visited)
{
    queue<int> pending;
    visited[s] = true;
    pending.push(s);
    while (!pending.empty())
    {
        int current = pending.front();
        pending.pop();
        cout << current << " ";
        for (int i = 0; i < n; i++)
        {
            if (i == current)
            {
                continue;
            }
            if (edges[s][i] == 1 && !visited[i])
            {
                pending.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS_main(int **edges, int n)
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
            bfsTraversal(edges, n, i, visited);
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

    BFS_main(edges, n);
}