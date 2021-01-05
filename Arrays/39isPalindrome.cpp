#include <iostream>
using namespace std;

bool isPalindrome(int a)
{
    int temp = a;
    int rem = 0, sum = 0;
    while (temp != 0)
    {
        rem = temp % 10;
        sum = sum * 10 + rem;
        temp /= 10;
    }
    if (sum == a)
    {
        return true;
    }
    else
        return false;
}

/*Complete the function below*/
int PalinArray(int a[], int n)
{ //add code here.
    for (int i = 0; i < n; i++)
    {
        if (!isPalindrome(a[i]))
        {
            return 0;
        }
    }

    return 1;
}