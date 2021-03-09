#include <iostream>
using namespace std;
int lps(string s)
{
    // Your code goes here
    int n = s.length();
    int temp[n];
    temp[0] = 0;

    //yycgicgyyycg

    // calculate the PI or lps table
    int j = 1, i = 0;
    while (j < n)
    {
        if (s[i] == s[j])
        {
            temp[j] = i + 1;
            j++;
            i++;
        }
        else
        {

            if (s[i - 1] == s[j])
            {

                temp[j] = i + 1;
            }
            else
            {
                i = 0;
                temp[j] = 0;
            }
            j++;
        }
    }
    for (int k = 0; k < n; k++)
    {
        cout << temp[k] << " ";
    }
    cout << endl;
    return temp[n - 1];
}
int main()
{
    // Your code goes here

    string s;
    cin >> s;
    cout << lps(s) << endl;
    return 0;
}