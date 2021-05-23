#include <iostream>
using namespace std;
// k = 0
// iamstrongacbcahhihhabbacbaabc
/**
 * k = 0
 * Even length palindrome
 * ....(char)(char)....
 * input : strongacbcahha
 * k = 11 left=10 right=12
 * countEven = 4
 * if(input[k] == input[k+1]) palindromeLength = 2
 * 
 *  if(input[left] == input[right])
 *  while(left >= 0 && right < n && input[left] == input[right] )
 *  left--; right++;
 * 
 * odd length palindrome
 * jfhdfhj abbba hgtughutgh countOdd = 5
 * 
 * k == k + 2 ---->
 * 
 * 
 * return max(countEven,countOdd)
*/

// k =0 , k+ 1 .....aa....
void findLongestPalindrome(string s)
{
    //abcd

    int l, h;
    int start = 0, palinLength = 1; //there is min 1 length palindrome
    for (int i = 1; i < s.length(); i++)
    {
        /*
        Check for even length palindrome
        checking adjacent characters
        */
        // abcdabcd
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