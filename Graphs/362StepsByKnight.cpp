#include <bits/stdc++.h>
using namespace std;

bool check(int u, int v, int N)
{
    return (u > 0 && u <= N && v > 0 && v <= N);
}

int xc[] = {-1, -1, -2, -2, +1, +1, +2, +2};
int yc[] = {-2, +2, -1, +1, -2, +2, -1, +1};

int minStepToReachTarget(int knightPos[], int targetPos[], int N)
{
    // code here
    bool vis[N + 1][N + 1];
    memset(vis, false, sizeof(vis));
    queue<pair<int, int>> q;
    q.push({knightPos[0], knightPos[1]});
    vis[knightPos[0]][knightPos[1]] = true;
    int lvl = 0;
    while (!q.empty())
    {
        int s = q.size();
        while (s--)
        {
            pair<int, int> p = q.front();
            q.pop();
            if (p.first == targetPos[0] && p.second == targetPos[1])
                return lvl;
            for (int dir = 0; dir < 8; dir++)
            {
                if (check(p.first + xc[dir], p.second + yc[dir], N) && !vis[p.first + xc[dir]][p.second + yc[dir]])
                {
                    vis[p.first + xc[dir]][p.second + yc[dir]] = true;
                    q.push({p.first + xc[dir], p.second + yc[dir]});
                }
            }
        }
        lvl++;
    }
}