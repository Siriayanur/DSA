#include <iostream>
#include <vector>
using namespace std;

int median(vector<vector<int>> &matrix, int m, int n)
{
    // code here

    int target = (m * n + 1) / 2;
    int a = INT_MAX;
    int b = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        a = min(a, matrix[i][0]);
        b = max(b, matrix[i][n - 1]);
    }
    int mid;
    while (a < b)
    {
        mid = (a + b) / 2;
        int count = 0;

        for (int i = 0; i < m; i++)
            count = count + (upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin());

        if (count < target)
            a = mid + 1;
        else
            b = mid;
    }
    return a;
}