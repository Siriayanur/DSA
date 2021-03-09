#include <iostream>
using namespace std;

int find(string s)
{
    int a = 0, b = 0;
    int res = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
            a++;
        if (s[i] == '1')
            b++;

        if (a == b)
        {
            res++;
            a = 0;
            b = 0;
        }
    }
    if (a != b)
    {
        return -1;
    }
    else
    {
        return res;
    }
}

int main()
{

    string s;
    cin >> s;
    cout << find(s) << endl;
    return 0;
}