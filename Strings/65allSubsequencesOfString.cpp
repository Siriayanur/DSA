#include <iostream>
using namespace std;

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