#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxLen(string s)
    {
        stack<int> st;
        // st.push(-1);
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                st.push(i);
            else
            {
                if (!st.empty())
                    st.pop();

                if (!st.empty())
                    ans = max(ans, i - st.top());
                else
                    st.push(i);
            }
        }
        return ans;
    }
    //More intuitive soln
    int findMaxLen2(string s)
    {
        int maxLength = 0;
        int left = 0, right = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                left++;

            if (s[i] == ')')
                right++;

            if (left == right)
                maxLength = max(maxLength, right * 2);

            if (right > left)
            {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '(')
                left++;

            if (s[i] == ')')
                right++;

            if (left == right)
                maxLength = max(maxLength, left * 2);

            if (left > right)
                left = right = 0;
        }
        return maxLength;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}