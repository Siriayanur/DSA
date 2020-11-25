#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*  APPROACH:

    * To get the subsetSum > remainingArraySum,we need to get subsetSum > 1/2(totalArraySum)
    * Sort the array (descending)
    * Start from the beginning(i.e) largest array
*/

int smallestSubset(int a[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += a[i];
    }
    int halfTotal = total / 2;
    int currentSum = 0, count = 0;

    sort(a, a + n, greater<int>());
    for (int i = 0; i < n; i++)
    {
        currentSum += a[i];
        count++;
        if (currentSum > halfTotal)
        {
            break;
        }
    }
    return count;
}

int main()
{
}