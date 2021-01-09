#include <bits/stdc++.h>
using namespace std;
#define MAX 5

void findPathUtil(int maze[MAX][MAX], int i, int j, int n, string path, vector<string> &result)
{
    if (i < 0 || j < 0 || i >= n || j >= n || maze[i][j] != 1)
    {
        return;
    }

    if (i == n - 1 && j == n - 1)
    {
        result.push_back(path);
        return;
    }

    maze[i][j] = -1;

    findPathUtil(maze, i + 1, j, n, path + "D", result);
    findPathUtil(maze, i - 1, j, n, path + "U", result);
    findPathUtil(maze, i, j + 1, n, path + "R", result);
    findPathUtil(maze, i, j - 1, n, path + "L", result);
    maze[i][j] = 1;
}

vector<string> findPath(int m[MAX][MAX], int n)
{
    vector<string> result;
    if (m[0][0] == 0)
    {
        return result;
    }
    findPathUtil(m, 0, 0, n, "", result);
    sort(result.begin(), result.end());
    return result;
}