#include <iostream>
using namespace std;
#include <queue>
void reverse(queue<int> &q)
{
    if (q.empty() || q.size() == 1)
    {
        return;
    }

    int temp = q.front();
    q.pop();
    reverse(q);
    q.push(temp);
}

queue<int> rev(queue<int> q)
{
    // add code here.
    reverse(q);
    return q;
}