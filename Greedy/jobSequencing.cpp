#include <bits/stdc++.h>
using namespace std;

class Job
{
public:
    char job;
    int deadline;
    int profit;
};

bool Comparator(Job a, Job b)
{
    return a.profit > b.profit;
}

void jobSequencing(Job input[], int n)
{
    sort(input, input + n, Comparator);
    int result[n];
    bool slot[n];
    int current_deadline = input[0].deadline;

    for (int i = 0; i < n; i++)
        slot[i] = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, input[i].deadline) - 1; j >= 0; j--)
        {
            if (!slot[j])
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (slot[i])
        {
            cout << input[result[i]].job << " ";
        }
    }
}

int main()
{
}