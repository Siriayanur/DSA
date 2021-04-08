#include <iostream>
#include <vector>
using namespace std;
int celebrity(vector<vector<int>> &M, int n)
{
    // code here
    vector<int> people;
    for (int i = 0; i < n; i++)
    {
        people.push_back(i);
    }

    int s = 0, e = n - 1;
    while (s <= e)
    {
        if (s == e)
        {
            break;
        }

        if (M[s][e])
        {
            s++;
        }
        else
        {
            e--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!M[i][s] && i != s)
        {
            return -1;
        }
    }
    return s;
}