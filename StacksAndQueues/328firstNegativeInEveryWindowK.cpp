#include <bits/stdc++.h>
using namespace std;
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    queue<int> pq;
    vector<long long> result;
    for (long long int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            pq.push(A[i]);
        }
    }

    for (long long int i = 0; i <= N - K; i++)
    {

        if (!pq.empty())
        {
            result.push_back(pq.front());
        }
        else
        {
            result.push_back(0);
        }

        if (pq.front() == A[i])
        {
            pq.pop();
        }
        if (A[i + K] < 0)
            pq.push(A[i + K]);
    }
    return result;
}