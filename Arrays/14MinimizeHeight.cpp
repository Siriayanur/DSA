#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//o(n) space

class Solution
{
public:
    int getMinDiff(int arr[], int n, int k)
    {
        // code here
        vector<pair<int, int>> store;
        vector<int> visited(n);
        for (int i = 0; i < n; i++)
        {
            if (arr[i] - k >= 0)
                store.push_back(make_pair(arr[i] - k, i));
            store.push_back(make_pair(arr[i] + k, i));
        }

        sort(store.begin(), store.end());
        int elements = 0, left = 0, right = 0;
        while (elements < n && right < store.size())
        {

            if (visited[store[right].second] == 0)
                elements++;
            visited[store[right].second]++;
            right++;
        }
        int ans = store[right - 1].first - store[left].first;
        while (right < store.size())
        {

            if (visited[store[left].second] == 1)
                elements--;

            visited[store[left].second]--;
            left++;

            while (elements < n && right < store.size())
            {
                if (visited[store[right].second] == 0)
                    elements++;

                visited[store[right].second]++;
                right++;
            }
            if (elements == n)
            {
                ans = min(ans, store[right - 1].first - store[left].first);
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};

//Correct answer
int getMinDiff(int a[], int n, int k)
{
    sort(a, a + n);
    int minEl, maxEl;
    int result = a[n - 1] - a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] >= k)
        {
            maxEl = max(a[i - 1] + k, a[n - 1] - k);
            minEl = min(a[0] + k, a[i] - k);
            result = min(result, maxEl - minEl);
        }
    }
    return result;
}
int main()
{
    int a[] = {1, 8, 5, 10};
    cout << getMinDiff(a, 4, 2);
    return 0;
}