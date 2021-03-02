#include <iostream>
using namespace std;

class Solution
{
public:
    // using swap sort logic
    int *findTwoElement2(int *arr, int n)
    {
        // code here
        int i = 0;
        int d, m;

        while (i < n)
        {
            while (arr[i] != i + 1)
            {
                if (arr[arr[i] - 1] == arr[i])
                {
                    d = arr[i];
                    break;
                }
                swap(arr[arr[i - 1]], arr[i]);
            }

            i++;
        }

        for (int j = 0; j < n; j++)
        {
            if (arr[j] != j + 1)
            {
                m = j + 1;
                break;
            }
        }

        int *result;
        result = new int[2];
        result[0] = d;
        result[1] = m;
        return result;
    }

    // Using another logic
    int *findTwoElement(int *arr, int n)
    {
        // code here
        int *a = new int(2);
        for (int i = 0; i < n; i++)
        {
            if (arr[abs(arr[i]) - 1] > 0)
            {
                arr[abs(arr[i]) - 1] = 0 - arr[abs(arr[i]) - 1];
            }
            else
            {
                a[0] = abs(arr[i]); //repeating number
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                a[1] = i + 1; //missing number
            }
        }

        return a;
    }
};