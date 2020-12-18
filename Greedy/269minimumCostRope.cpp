#include <bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n)
{
    // Your code here
    priority_queue<long long, vector<long long>, greater<long long>> pq(arr, arr + n);
    long long count = 0;

    while (pq.size() != 1)
    {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();

        count += (a + b);
        pq.push(a + b);
    }
    return count;
}

int main()
{
    long long a[] = {4, 3, 2, 6};
    cout << minCost(a, 4) << endl;
    return 0;
}