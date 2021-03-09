#include <iostream>
using namespace std;

bool shuffleCheck(string first, string second, string result)
{

    // check length of result is same as
    // sum of result of first and second
    if (first.length() + second.length() != result.length())
    {
        return false;
    }
    // variables to track each character of 3 strings
    int i = 0, j = 0, k = 0;

    // iterate through all characters of result
    while (k != result.length())
    {

        // check if first character of result matches with first character of first string
        if (i < first.length() && first.charAt(i) == result.charAt(k))
            i++;

        // check if first character of result matches the first character of second string
        else if (j < second.length() && second.charAt(j) == result.charAt(k))
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
}