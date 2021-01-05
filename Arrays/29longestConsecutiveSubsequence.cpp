#include <iostream>
#include <unordered_set>

using namespace std;

int findLongestConseqSubseq(int a[], int n)
{
    int result = 0;
    unordered_set<int, int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {

        // You searched for previous element, if its not found the next to last element pointer is
        // returned
        if (s.find(a[i] - 1) == s.end())
        {
            // insert and find take o(1)
            int current = a[i];
            while (s.find(current) != s.end())
            {
                current++;
            }
            result = max(result, current - a[i]);
        }
    }
    return result;
}