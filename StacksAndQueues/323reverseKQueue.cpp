#include <bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> st;
    int i = 0;
    while (i < k)
    {
        st.push(q.front());
        q.pop();
        i++;
    }

    queue<int> unchanged;
    while (!q.empty())
    {
        unchanged.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    while (!unchanged.empty())
    {
        q.push(unchanged.front());
        unchanged.pop();
    }
    return q;
}