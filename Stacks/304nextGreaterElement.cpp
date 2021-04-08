#include <iostream>
using namespace std;
#include <stack>
#include <vector>

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    // Your code here
    vector<long long> result;
    stack<long long> st;

    long long currentMax = arr[n - 1];
    result.push_back(-1);
    for (long long i = n - 2; i >= 0; i--)
    {

        if (arr[i] < arr[i + 1])
        {
            st.push(arr[i + 1]);
            result.push_back(arr[i + 1]);
        }
        else
        {
            while (!st.empty() && st.top() <= arr[i])
                st.pop();

            if (st.empty())
                result.push_back(-1);

            else
                result.push_back(st.top());
        }
    }
    reverse(result.begin(), result.end());
    return result;
}
