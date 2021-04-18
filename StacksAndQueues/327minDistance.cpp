#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> nearest(vector<vector<int>> grid)
{
    // Code here
    int res[501][501];
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> pq;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                pq.push(make_pair(i, j));
                res[i][j] = 0;
            }
            else
            {
                res[i][j] = INT_MAX;
            }
        }
    }

    int row_value[] = {0, 0, -1, 1};
    int col_value[] = {-1, 1, 0, 0};
    int diff = 0;

    while (!pq.empty())
    {
        int currentSize = pq.size();
        for (int i = 0; i < currentSize; i++)
        {
            pair<int, int> current = pq.front();
            pq.pop();
            res[current.first][current.second] = min(diff, res[current.first][current.second]);
            for (int k = 0; k < 4; k++)
            {
                int row = current.first + row_value[k];
                int col = current.second + col_value[k];

                if (row >= 0 && row < n && col >= 0 && col < m && res[row][col] == INT_MAX)
                {
                    pq.push(make_pair(row, col));
                }
            }
        }
        diff++;
    }
    vector<vector<int>> vec(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vec[i][j] = res[i][j];
        }
    }
    return vec;
}