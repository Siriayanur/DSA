#include <iostream>
#include <stack>

using namespace std;

int minBracket(string s)
{

    int count = 0;
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{')
        {
            st.push(s[i]);
        }
        else if (s[i] == '}')
        {

            if (st.empty())
            {
                st.push(s[i]);
            }
            else if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else if (!st.empty() && st.top() != '{')
            {
                st.push(s[i]);
            }
        }
    }

    while (!st.empty())
    {
        char c1 = st.top();
        st.pop();
        char c2 = st.top();
        st.pop();
        if (c1 == c2)
            count++;
        if (c1 != c2)
        {
            count = count + 2;
        }
    }
    return count;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        if (s.length() % 2 != 0)
            cout << "-1" << endl;
        else
            cout << minBracket(s) << endl;
    }

    return 0;
}