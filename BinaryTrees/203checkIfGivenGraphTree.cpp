#include <iostream>
using namespace std;

bool isCycle(int **graph, int v, int parent, bool *visited)
{
    visited[v] = true;

    for (int i = 0; i < n; i++)
    {
        if (graph[v][i])
        {
            if (!visited[i])
            {
                if (isCycle(graph, i, v, visited))
                {
                    return true;
                }
            }
            else if (visited[i] && i != parent)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int e;
    cin >> e;
    int n;
    cin >> n;

    bool **graph = new int *[n];

    for (int i = 0; i < n; i++)
    {
        graph[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    bool *visited = new bool[n];

    for (int i = 0; i < n; i++)
    {

        visited[i] = false;
    }

    for (int i = 0; i < e; i++)
    {
        int st, en;
        cin >> st >> en;
        graph[st][en] = 1;
        graph[en][st] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (isCycle(graph, i, -1, visited))
        {
            cout << "Not a tree" << endl;
            return 0;
        }
    }

    //Check if there are 2 or more connected components which are not at all visited
    for (int i = 0; i < e; i++)
    {
        if (!visited[i])
        {
            cout << "Not a tree" << endl;
            return 0;
        }
    }
    cout << "Yes Graph is Tree" << endl;
}