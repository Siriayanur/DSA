#include <bits/stdc++.h>
using namespace std;

class Triplet
{

public:
    int start;
    int end;
    int position;
};

bool Comparator(Triplet a, Triplet b)
{
    return a.end < b.end;
}

void maxMeetings(int start[], int end[], int n)
{
    // Your code here

    Triplet activity[n];

    for (int i = 0; i < n; i++)
    {
        activity[i].start = start[i];
        activity[i].end = end[i];
        activity[i].position = i + 1;
    }
    sort(activity, activity + n, Comparator);

    int j = 0;
    cout << activity[j].position << " ";

    for (int i = 1; i < n; i++)
    {

        if (activity[j].end < activity[i].start)
        {
            cout << activity[i].position << " ";
            j = i;
        }
    }
}

int main()
{
    return 0;
}