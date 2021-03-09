#include <stack>
#include <iostream>
using namespace std;

bool ispar(string s)
{
    // Your code here
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (s[i] == '}' || s[i] == ')' || s[i] == ']')
        {

            if (st.empty())
                return false;

            else if (s[i] - st.top() == 2 || s[i] - st.top() == 1)
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }

    return st.empty();
}