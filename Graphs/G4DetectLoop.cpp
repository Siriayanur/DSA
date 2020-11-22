#include <iostream>
using namespace std;

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
}