#include <iostream>
using namespace std;

vector<int> max_of_subarrays(int *arr, int n, int k)
{
    // your code here
    vector<int> result;
    deque<int> d(k);

    int i;
    for (i = 0; i < k; i++)
    {
        while (!d.empty() && arr[i] >= arr[d.back()])
            d.pop_back();
        d.push_back(i);
    }

    for (; i < n; i++)
    {
        result.push_back(arr[d.front()]);

        while (!d.empty() && d.front() <= i - k)
        {
            d.pop_front();
        }

        while (!d.empty() && arr[i] >= arr[d.back()])
            d.pop_back();

        d.push_back(i);
    }
    result.push_back(arr[d.front()]);
    return result;
}