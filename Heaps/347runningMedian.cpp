#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int count = 0;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Function to insert heap
    void insertHeap(int &x)
    {
        if (maxHeap.size() == 0 || x < maxHeap.top())
        {
            maxHeap.push(x);
        }
        else
            minHeap.push(x);

        count++;
        balanceHeaps();
    }

    // Function to balance heaps
    void balanceHeaps()
    {
        if (maxHeap.size() - minHeap.size() == 2)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if (minHeap.size() - maxHeap.size() == 2)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    // Function to return getMedian
    double getMedian()
    {
        double median;
        if (count % 2 == 0)
        {
            median = (maxHeap.top() + minHeap.top()) / 2;
        }
        else
        {
            if (maxHeap.size() > minHeap.size())
            {
                median = maxHeap.top();
            }
            else
            {
                median = minHeap.top();
            }
        }

        return median;
    }
};

int main()
{
    int n, x;
    int t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> x;
            ob.insertHeap(x);
            cout << floor(ob.getMedian()) << endl;
        }
    }
    return 0;
}