#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> valueEqualToIndex(int a[], int n)
    {
        // code here
        vector<int> result;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == i + 1)
            {
                result.push_back(a[i]);
            }
        }
        return result;
    }
};