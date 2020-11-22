#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class train
{
public:
    int departure;
    int arrival;
};
int findPlatform(int arr[], int dep[], int n)
{
    // Your code here
    vector<train> platforms;
    train t = train();
    t.arrival = arr[0];
    t.departure = dep[0];

    int j;
    for (int i = 1; i < n; i++)
    {
        bool updated = false;
        for (j = platforms.size() - 1; j >= 0; j--)
        {
            if (arr[i] > (platforms[j].departure))
            {
                //continue
                updated = true;
                platforms[j].arrival = arr[i];
                platforms[j].departure = dep[i];
                break;
            }
        }
        if (!updated)
        {
            //continue
            train t = train();
            t.arrival = arr[i];
            t.departure = dep[i];
            platforms.push_back(t);
        }
    }
    return platforms.size();
}
int main()
{
    int n;
    cin >> n;
    int arr[n], dep[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cin >> dep[i];
    }
    cout << findPlatform(arr, dep, n);
    return 0;
}