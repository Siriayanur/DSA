#include <iostream>
using namespace std;

class Solution
{
public:
    int middle(int A, int B, int C)
    {
        //code here//Position this line where user code will be pasted.
        if ((A - B) * (A - C) < 0)
            return A;
        else if ((B - A) * (B - C) < 0)
            return B;
        else
            return C;
    }
};