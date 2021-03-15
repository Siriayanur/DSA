#include <iostream>
#include <vector>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> matrix, int m, int n)
{
    // code here
    vector<int> result;
    int sr = 0, sc = 0, er = m - 1, ec = n - 1;

    while (sr <= er && sc <= ec && sr >= 0 && er <= m - 1 && sc >= 0 && ec <= n - 1)
    {

        for (int i = sc; i <= ec; i++)
            result.push_back(matrix[sr][i]);

        sr++;

        if (sr > er)
            break;

        for (int j = sr; j <= er; j++)
            result.push_back(matrix[j][ec]);

        ec--;

        if (ec < 0 || ec < sc)
            break;

        for (int k = ec; k >= sc; k--)
            result.push_back(matrix[er][k]);

        er--;
        if (er < sr || er < 0)
            break;

        for (int l = er; l >= sr; l--)
            result.push_back(matrix[l][sc]);

        sc++;
    }
    return result;
}