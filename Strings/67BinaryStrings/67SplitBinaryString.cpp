#include <iostream>
using namespace std;
/**
 * 
 * 
 * Given a binary string str of length N, the task is to find the maximum count of      substrings str can be divided into such that all the substrings are balanced i.e. they have equal number of 0s and 1s. If it is not possible to split str satisfying the conditions then print -1.
 * 
 * 
*/
int find(string s)
{
    int a = 0, b = 0;
    int res = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
            a++;
        else if (s[i] == '1')
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
/**
 * 
*       if (s[i] == '0')
                a++;
        else if (s[i] == '1')
                b++;
 * 
 *  if the "else if" was if then it will increase time complexity as if would check unnecessarily for every input
 *  use else if() or if,else block
 * 
*/