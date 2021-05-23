#include <iostream>
using namespace std;
//https://www.programiz.com/java-programming/examples/check-valid-shuffle-of-strings
bool shuffleCheck(string first, string second, string result)
{

    if (first.length() + second.length() != result.length())
    {
        return false;
    }

    int i = 0, j = 0, k = 0;

    // iterate through all characters of result
    while (k != result.length())
    {

        // check if first character of result matches with first character of first string
        if (i < first.length() && first[i] == result[k])
            i++;

        // check if first character of result matches the first character of second string
        else if (j < second.length() && second[j] == result[k])
            j++;

        // if the character doesn't match
        else
        {
            return false;
        }

        // access next character of result
        k++;
    }

    // after accessing all characters of result
    // if either first or second has some characters left
    if (i < first.length() || j < second.length())
    {
        return false;
    }

    return true;
}

int main()
{
    string s1 = "XY";
    string s2 = "12";
    string res = "1XY2";
    string res2 = "Y12X";
    cout << shuffleCheck(s1, s2, res) << endl;
    cout << shuffleCheck(s1, s2, res2) << endl;
}