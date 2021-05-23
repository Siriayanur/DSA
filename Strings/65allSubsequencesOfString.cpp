#include <iostream>
using namespace std;
/**
 * abcd
 * Order to be monitored - need not be contiguous in the original string (subsequence)
 * 
 * a,b,c,d,ab,ac,ad,abc,acd,abcd,bc,bd,bcd,cd
 * 
 * 
 * a --> skip 'a' call on 'bcd'
 *   --> include 'a' call on 'bcd', substr='a'
 * 
 * b --> skip 'b' call on 'cd' ,subtr='a'
 *   --> include 'b' call on 'cd', substr='ab'    
 * .....
 *
*/
void helper(string substring, int i, int n, string s)
{
    if (i == n)
    {
        cout << substring << endl;
    }
    helper(substring, i + 1, n, s);
    substring += s[i];
    helper(substring, i + 1, n, s);
}

int main()
{
    string s;
    cin >> s;
    helper("", 0, s.length(), s);
}