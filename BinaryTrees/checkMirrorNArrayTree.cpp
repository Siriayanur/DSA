#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int checkMirrorTree(int n, int e, int A[], int B[])
    {
        // code here
        unordered_map<int, stack<int>> map;
        for (int i = 0; i < 2 * e; i = i + 2)
        {
            map[A[i]].push(A[i + 1]);
        }

        for (int i = 0; i < 2 * e; i = i + 2)
        {
            if (map[B[i]].top() != B[i + 1])
                return 0;
            map[B[i]].pop();
        }
        return 1;
    }
};