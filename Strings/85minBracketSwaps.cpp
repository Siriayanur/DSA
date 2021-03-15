#include <iostream>
#include <vector>

using namespace std;

int minimumNumberOfSwaps(string s)
{
    // code here
    vector<int> pos;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '[')
            pos.push_back(i);
    }

    int count = 0;
    int p = 0;
    int sum = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '[')
        {
            p++;
            count++;
        }
        else if (s[i] == ']')
        {
            count--;
        }

        if (count < 0)
        {

            sum += pos[p] - i;
            swap(s[i], s[pos[p]]);
            p++;

            count = 1;
        }
    }
    return sum;
}