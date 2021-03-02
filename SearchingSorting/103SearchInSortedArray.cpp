#include <iostream>
using namespace std;
int findMinElement(int nums[], int n)
{
    if (nums[0] < nums[n - 1])
    {
        return 0;
    }
    int pivot = -1;
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        if (nums[start] <= nums[end])
        {
            return start;
        }
        int mid = (start + end) / 2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;
        if (nums[mid] <= nums[prev] && nums[mid] <= nums[next])
        {
            pivot = mid;
            break;
        }
        if (nums[start] <= nums[mid])
        {
            start = mid + 1;
        }
        else if (nums[mid] <= nums[end])
        {
            end = mid - 1;
        }
    }
    return pivot;
}

int binarySearch(int a[], int s, int e, int target)
{
    if (s > e)
    {
        return -1;
    }
    int mid = (s + e) / 2;
    if (a[mid] == target)
        return mid;
    else if (target < a[mid])
    {
        e = mid - 1;
        return binarySearch(a, s, e, target);
    }
    else
    {
        s = mid + 1;
        return binarySearch(a, s, e, target);
    }
}
int search(int nums[], int n, int target)
{

    if (target == nums[0])
    {
        return 0;
    }
    if (target == nums[n - 1])
    {
        return n - 1;
    }
    int minElement = findMinElement(nums, n);
    if (target < nums[n - 1])
    {
        return binarySearch(nums, minElement, n - 1, target);
    }
    else
    {
        return binarySearch(nums, 0, minElement - 1, target);
    }
}

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int target;
        cin >> target;
        cout << search(a, n, target) << endl;
    }
    return 0;
}