
#include <climits>
#include <bits/stdc++.h>
using namespace std;

stack<int> minStack;

void push(stack<int> &s, int a)
{
    // Your code goes here

    if (s.empty())
    {
        minStack.push(a);
    }
    else
    {
        if (a < minStack.top())
            minStack.push(a);
    }
    s.push(a);
}

bool isFull(stack<int> &s, int n)
{
    // Your code goes here
    return s.size() == n;
}

bool isEmpty(stack<int> &s)
{
    // Your code goes here
    return s.size() == 0;
}

int pop(stack<int> &s)
{
    // Your code goes here
    int temp = s.top();
    s.pop();
    return temp;
}

int getMin(stack<int> &s)
{
    // Your code goes here
    if (s.empty())
    {
        return -1;
    }
    return minStack.top();
}