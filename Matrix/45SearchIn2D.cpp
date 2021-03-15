#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{

    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < matrix.size(); i++)
    {
        if (target >= matrix[i][0] && target <= matrix[i][m - 1])
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == target)
                    return true;
            }
        }
    }
    return false;
}