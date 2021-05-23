#include <iostream>
using namespace std;

string findPattern(int n)
{
    if (n == 1)
        return "1";
    if (n == 2)
        return "11";

    string str = "11";
    // previous string n=2 n=1
    for (int i = 3; i <= n; i++)
    {
        string temp = "";
        int count = 1;

        for (int j = 0; j < str.length(); j++)
        {

            if (str[j] != str[j + 1])
            {
                temp += count + '0';

                temp += str[j];

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
    cout << findPattern(7) << endl;
    return 0;
}
