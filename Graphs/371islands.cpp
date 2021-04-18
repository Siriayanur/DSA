#include <iostream>
using namespace std;

#define MAX 500
int visited[MAX][MAX];

class Solution
{

public:
    void dfs(int i, int j, int n, int m, vector<vector<char>> &grid)
    {

        //Base condition
        if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || grid[i][j] == '0')
            return;

        visited[i][j] = 1;

        dfs(i, j + 1, n, m, grid);
        dfs(i + 1, j + 1, n, m, grid);
        dfs(i + 1, j, n, m, grid);
        dfs(i + 1, j - 1, n, m, grid);
        dfs(i, j - 1, n, m, grid);
        dfs(i - 1, j - 1, n, m, grid);
        dfs(i - 1, j, n, m, grid);
        dfs(i - 1, j + 1, n, m, grid);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        // Code here

        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                visited[i][j] = 0;

        int islands = 0;
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {

                if (grid[i][j] == '1' && !visited[i][j])
                {
                    dfs(i, j, n, m, grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};