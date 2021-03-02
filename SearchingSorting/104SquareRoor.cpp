#include <iostream>
#include <math.h>
using namespace std;
class Solution
{
public:
    int countSquares(int n)
    {
        // code here
        float a = sqrt(n);
        if (floor(a) == a)
        {
            return a - 1;
        }

        return a;
    }
};