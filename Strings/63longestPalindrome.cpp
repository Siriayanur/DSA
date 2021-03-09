#include <iostream>
using namespace std;

void findLongestPalindrome(string s)
{

    int l, h;
    int start = 0, palinLength = 1; //there is min 1 length palindrome
    for (int i = 1; i < s.length(); i++)
    {
        /*
        Check for even length palindrome
        checking adjacent characters
        */
        l = i - 1;
        h = i;
        while (l >= 0 && h < s.length() && s[l] == s[h])
        {
            if (h - l + 1 > palinLength)
            {
                start = l;
                palinLength = h - l + 1;
            }
            l--;
            h++;
        }

        /*
        Check for odd length palindrome
        jump 2 chars and check if equal abcba a==c,b==b,c==a
        b==b indicates that bcb forms palindrome
        */
        l = i - 1;
        h = i + 1;
        while (l >= 0 && h < s.length() && s[l] == s[h])
        {
            if (h - l + 1 > palinLength)
            {
                start = l;
                palinLength = h - l + 1;
            }
            l--;
            h++;
        }
    }
    for (int i = start; i <= (start + palinLength - 1); i++)
    {
        cout << s[i];
    }

    cout << endl;
}

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        findLongestPalindrome(s);
    }

    return 0;
}