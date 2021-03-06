#include <bits/stdc++.h>
using namespace std;
#include <iostream>
using namespace std;

/*
Methods to check substring 
*/
int method0(string s1, string s2)
{
    int M = s1.length();
    int N = s2.length();

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++)
    {
        int j;

        /* For current index i, check for
 pattern match */
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;

        if (j == M)
            return i;
    }

    return -1;
}
int method1(string str, string target)
{

    int t = 0;
    int len = str.length();
    int i;

    // Iterate from 0 to len - 1
    for (i = 0; i < len; i++)
    {
        if (t == target.length())
            break;
        if (str.charAt(i) == target.charAt(t))
            t++;
        else
            t = 0;
    }

    return t < target.length() ? -1 : i - t;
}
int method2()
{

    string str2 = "app";
    string str = "an apple";

    int found = str.find(str2);

    if (found != string::npos)
    {
        cout << "first 'app' found at: " << int(found) << endl;
    }
}
bool isReversed(string s1, string s2)
{
    string temp = s1 + s1;

    if (method1(temp, s2) != -1)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    string s1 = "abcd";
    string s2 = "badc";
    string s3 = "cdab";

    if (isReversed(s1, s2))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    if (isReversed(s1, s3))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}