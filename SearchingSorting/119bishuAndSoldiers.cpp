
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int temp[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        temp[i] = sum;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int power;
        cin >> power;

        int i = 0;

        while (a[i] <= power && i < n)
        {
            i++;
        }
        cout << i << " " << temp[i - 1] << endl;
    }
    return 0;
}