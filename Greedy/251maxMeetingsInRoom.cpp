#include <bits/stdc++.h>
using namespace std;

class Meeting
{
public:
    int start;
    int end;
    int position;
};

bool Comparator(Meeting a, Meeting b)
{

    return a.end < b.end;
}

void maxMeetings(int s[], int e[], int n)
{
    Meeting meetings[n];
    for (int i = 0; i < n; i++)
    {
        meetings[i].start = s[i];
        meetings[i].end = e[i];
        meetings[i].position = i + 1;
    }
    sort(meetings, meetings + n);

    int j = 0;
    cout << meetings[0].position << " ";
    for (int i = 1; i < n; i++)
    {
        if (meetings[j].end < meetings[i].start)
        {
            cout << meetings[i].position << " ";
            j = i;
        }
    }
}

int main()
{
    int s[] = {1, 3, 0, 5, 8, 5};

    // Finish time
    int f[] = {2, 4, 6, 7, 9, 9};

    // Number of meetings.
    int n = sizeof(s) / sizeof(s[0]);

    // Function call
    maxMeetings(s, f, n);

    return 0;
}