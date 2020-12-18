#include <iostream>
using namespace std;

void cyclicRotate(int a[], int n)
{

    int temp = a[n - 1];
    int i;
    for (i = n - 1; i > 0; i--)
    {
        a[i] = a[i - 1];
    }

    /*
    0 1 2 3 4
    1 1 2 3 4


    
    resultant --> _ 1 
    
    */
    a[i] = temp;
}

// void printArray(int a[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         cout << a[i] << " ";
//     }
// }

int main()
{
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
        cyclicRotate(a, n);
        // printArray(a, n);
    }
}