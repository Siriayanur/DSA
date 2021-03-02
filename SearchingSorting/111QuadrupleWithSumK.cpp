#include <bits/stdc++.h>
using namespace std;

//Using 4 for loops
vector<vector<int>> findFour1(int a[], int n, int k)
{

    vector<vector<int>(4)> result;
    int index = 0;
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            for (int k = j + 1; k < n - 1; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    if (a[i] + a[j] + a[k] + a[l] == k)
                    {
                        result[index++].push_back(a[i], a[j], a[k], a[l]);
                    }
                }
            }
        }
    }
    return result;
}
vector<vector<int>> findFour2(int a[], int n, int k)
{

    int index = 0;
    vector<vector<int>(4)> result;
    int index = 0;
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int left = j + 1;
            int right = n - 1;
            while (left < right)
            {
                if (a[i] + a[j] + a[left] + a[right] == k)
                {
                    result[index++].push_back(a[i], a[j], a[left], a[right]);
                }
                else if (a[i] + a[j] + a[left] + a[right] < k)
                {
                    left++;
                }
                else
                    right--;
            }
        }
    }
    return result;
}



int main()
{
}