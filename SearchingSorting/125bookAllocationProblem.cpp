#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /*
     Learnt this from code library but
     it fails at one particular test
     The code is logically correct
    */
    bool solve(int a[], int n, int mid, int m)
    {
        int sum = 0;
        int students = 1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > mid)
                return false;

            if (a[i] + sum > mid)
            {
                students++;
                sum = a[i];
                if (students > m)
                    return false;
            }
            else
            {
                sum += a[i];
            }
        }
        return true;
    }

    int findPages(int a[], int n, int m)
    {
        if (m > n)
        {
            return -1;
        }
        sort(a, a + n);
        //code here
        int lb = a[0];
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
        }
        int ub = sum;
        while (lb <= ub)
        {
            int mid = lb + (ub - lb) / 2;
            if (solve(a, n, mid, m))
            {
                ans = mid;
                ub = mid - 1;
            }
            else
            {
                lb = mid + 1;
            }
        }
        return ans;
    }

    /*
     Passes all test cases in GFG
    */
    int findPages1(int arr[], int n, int m)
    {
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += arr[i];
        }

        int start = arr[0];
        int end = sum;

        int maxPages = INT_MAX;

        while (start <= end)
        {
            bool f = false;
            int mid = (end + start) / 2;
            //checking for this min;
            int t = 1;
            int i = 0;
            int temp = 0;

            while (i < n)
            {
                if (t > m)
                {
                    f = true;
                    break;
                }
                temp += arr[i];
                if (temp > mid)
                {
                    t++;
                    temp = 0;
                }
                else
                {
                    i++;
                }
            }
            if (f)
            {
                //Not possible
                start = mid + 1;
            }
            else
            {
                if (mid < maxPages)
                {
                    maxPages = mid;
                }
                end = mid - 1;
            }
        }
        if (maxPages == INT_MAX)
        {
            return -1;
        }
        return maxPages;
    }
};

int main()
{
}