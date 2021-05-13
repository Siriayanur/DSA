#include <bits/stdc++.h>
using namespace std;

//Similar approach

class Solution
{
public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n)
    {
        int min_index = 0, max_index = n - 1;
        int max = arr[n - 1] + 1;

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                arr[i] = (arr[max_index] % max) * max + arr[i];
                max_index--;
            }
            else
            {

                arr[i] = (arr[min_index] % max) * max + arr[i];
                min_index++;
            }
        }
        // Your code here
        for (int i = 0; i < n; i++)
        {
            arr[i] = arr[i] / max;
        }
    }
};