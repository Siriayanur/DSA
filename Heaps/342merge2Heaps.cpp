#include <iostream>
using namespace std;

void maxHeapify(int arr[], int n, int idx)
{

    if (idx >= n)
        return;

    int l = 2 * idx + 1;
    int r = 2 * idx + 2;

    int max = idx;
    if (l < n && arr[l] > arr[idx])
    {
        max = l;
    }
    else
        max = idx;

    if (r < n && arr[r] > arr[max])
        max = r;

    if (max != idx)
    {
        swap(arr[idx], arr[max]);
        maxHeapify(arr, n, max);
    }
}

void buildHeap(int merged[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        maxHeapify(merged, n, i);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int merged[m + n];

        for (int i = 0; i < n; i++)
            cin >> merged[i];

        for (int i = 0; i < m; i++)
            cin >> merged[n + i];

        buildHeap(merged, n + m);

        for (int i = 0; i < m + n; i++)
        {
            cout << merged[i] << " ";
        }
        cout << endl;
    }
    return 0;
}