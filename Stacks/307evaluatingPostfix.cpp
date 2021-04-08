#include <iostream>
#include <stack>
using namespace std;

int evaluate(int a, int b, char operand)
{
    int res;
    switch (operand)
    {
    case '*':
        res = a * b;
        break;
    case '/':
        if (b != 0)
            res = a / b;
        else
            res = 0;
        break;

    case '-':
        res = a - b;
        break;

    case '+':
        res = a + b;
        break;
    }
    return res;
}

int evaluatePostfix(string S)
{
    // Your code here
    stack<int> st;
    int i = 0;
    while (i < S.length())
    {
        int res;
        if (S[i] == '*' || S[i] == '/' || S[i] == '-' || S[i] == '+')
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            res = evaluate(a, b, S[i]);
            st.push(res);
        }
        else
        {
            st.push(S[i] - '0');
        }
        i++;
    }
    return st.top();
}