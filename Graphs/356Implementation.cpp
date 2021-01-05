#include <iostream>
//Implementing basic graphs
using namespace std;

void print(int **edges, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (edges[i][j] == 1)
            {
                cout << i << "->" << j << endl;
            }
        }
    }
}

int main()
{
    //n -> no of nodes
    //e -> no of edges

    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    bool *visited = new bool[n];
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

    print(edges, n);
    return 0;
}