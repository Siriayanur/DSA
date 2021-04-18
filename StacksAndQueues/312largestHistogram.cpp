#include <iostream>
#include <stack>

using namespace std;
class Solution
{
public:
    long long getMaxArea(long long arr[], int n)
    {

        // Your code here
        stack<long long> st;
        long long maxArea = 0;
        long long i;
        long long left_index = -1, right_index = -1;

        for (i = 0; i < n; i++)
        {
            right_index = i;
            if (st.empty())
                st.push(i);

            else
            {
                if (arr[st.top()] < arr[i])
                {
                    st.push(i);

                    else
                    {

                        while ((!st.empty()) && (arr[st.top()] >= arr[i]))
                        {

                            long long current = arr[st.top()];
                            st.pop();

                            if (st.empty())
                                left_index = -1;

                            else
                                left_index = st.top();

                            maxArea = max(current * (right_index - left_index - 1), maxArea);
                        }

                        st.push(i);
                    }
                }
            }

            right_index = i;

            while (!st.empty())
            {
                long long current = arr[st.top()];
                st.pop();

                if (!st.empty())
                    left_index = st.top();
                else
                    left_index = -1;

                maxArea = max((current * (right_index - left_index - 1)), maxArea);
            }
            return maxArea;
        }
    }
};
int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr, n) << endl;
    }
    return 0;
}
