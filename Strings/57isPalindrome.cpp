#include <iostream>
using namespace std;

int isPlaindrome(char a[])
{
    // Your code goes here
    int n = 0;
    int i = 0;

    while (a[n] != '\0')
        n++;

    int j = n - 1;

    while (i < j)
    {
        if (a[i] != a[j])
        {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}
