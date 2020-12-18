#include <iostream>
using namespace std;

void reverseArray(int a[], int n)
{
    int start = 0, end = n - 1;
    for (int start = 0; start <= end;)
    {
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
}

void reverseArrayRecursion(int a[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int temp = a[start];
    a[start] = a[end];
    a[end] = temp;

    reverseArrayRecursion(a, start + 1, end - 1);
}

int main()
{
}