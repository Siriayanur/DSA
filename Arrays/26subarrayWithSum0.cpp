#include <unordered_map>
#include <iostream>
using namespace std;

//Complete this function
// My code
bool subArrayExists(int a[], int n)
{
    //Your code here
    if (n == 2)
    {
        return (a[0] + a[1] == 0);
    }
    unordered_map<int, int> ourmap;
    int currentSum = 0;
    ourmap[0] = 1;
    for (int i = 0; i < n; i++)
    {

        currentSum += a[i];
        if (ourmap.count(currentSum) > 0)
        {
            return true;
        }

        ourmap[currentSum]++;
    }
    return false;
}

// Another good code
bool subArrayExists(int arr[], int n)
{
    unordered_map<int, int> m;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {

        if (arr[i] == 0)
            return 1;

        sum += arr[i];
        if (sum == 0)
            return 1;

        if (m[sum] >= 1)
            return 1;
        m[sum]++;
    }
    return 0;
}