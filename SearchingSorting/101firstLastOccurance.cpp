#include <iostream>
using namespace std;

int main()
{
    //code
    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        int start = 0, end = 0;
        cin >> n;
        cin >> x;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == x)
            {
                start++;
                end = i;
                if (start == 1)
                {
                    cout << i << " ";
                }
            }
        }
        if (start == 0)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << end << endl;
        }
    }
    return 0;
}