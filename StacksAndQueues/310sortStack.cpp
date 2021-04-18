#include <iostream>
#include <iostream>
#include <stack>
using namespace std;

void insertInSortedStack(stack<int> &s, int element)
{
    if (s.empty() || element > s.top())
    {
        s.push(element);
    }
    else
    {
        int temp = s.top();
        s.pop();
        insertInSortedStack(s, element);
        s.push(temp);
    }
}

void sort(stack<int> &s)
{
    //Your code here
    if (!s.empty())
    {
        int element = s.top();
        s.pop();
        sort();
        insertInSortedStack(s, element);
    }
}
