#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat)
{
    int elements[N * N];
    int k = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            elements[k++] = Mat[i][j];
    sort(elements, elements + (N * N));
    int idx = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            Mat[i][j] = elements[idx++];

    return Mat;
}