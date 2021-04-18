#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra)
{
    if (input.size() == 0 || input.size() == 1)
    {
        return;
    }

    int temp = input.top();
    input.pop();

    reverseStack(input, extra);
    while (!input.empty())
    {
        extra.push(input.top());
        input.pop();
    }

    input.push(temp);
    while (!extra.empty())
    {
        extra.push(input.top());
        extra.pop();
    }
}
