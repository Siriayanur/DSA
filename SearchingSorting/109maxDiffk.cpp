#include <iostream>
using namespace std;

int findElementWithMaxDiffk(int input[], int n, int x, int k)
{
    int i = 0;
    while (i < n)
    {
        if (input[i] == x)
            return i;

        i = i + max(1, abs(input[i] - x) / k);
    }
    return -1;
}
