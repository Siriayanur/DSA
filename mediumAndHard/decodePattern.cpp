#include <iostream>
using namespace std;

string findPattern(int n)
{
    if (n == 1)
        return "1";
    if (n == 2)
        return "11";

    string str = "11";

    for (int i = 3; i <= n; i++)
    {

        str += '$';
        string temp = "";
        int count = 1;
        for (int j = 1; j < str.length(); j++)
        {
            if (str[j] != str[j - 1])
            {
                temp += count + '0';
                temp += str[j - 1];
                count = 1;
            }
            else
            {
                count++;
            }
        }
        str = temp;
    }
    return str;
}

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << findPattern(n) << endl;
    }

    return 0;
}