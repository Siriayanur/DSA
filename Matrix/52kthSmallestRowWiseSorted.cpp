#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> pp;

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    //Your code here
    priority_queue<pp, vector<pp>, greater<pp>> pq;

    for (int i = 0; i < n; i++)
    {
        pp curr = make_pair(mat[i][0], make_pair(i, 0));
        pq.push(curr);
    }

    while (!pq.empty())
    {
        k--;

        pp current = pq.top();

        pq.pop();

        if (k == 0)
        {
            return current.first;
        }

        pair<int, int> index = current.second;
        int i = index.first;
        int j = index.second;

        if (j < n - 1)
        {
            pp c = make_pair(mat[i][j + 1], make_pair(i, j + 1));
            pq.push(c);
        }
    }
    return -1;
}
