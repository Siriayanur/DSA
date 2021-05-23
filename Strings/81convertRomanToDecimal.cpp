#include <iostream>
using namespace std;

int getValue(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;

    return -1;
}

int romanToDecimal(string &str)
{
    // code here
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        int s1 = getValue(str[i]);

        //If there is atleast one more character to check next then get its value
        if (i + 1 < str.length())
        {
            int s2 = getValue(str[i + 1]);

            //If the next character has a value lesser than current then anyway
            // it will get added in its turn so just add the current character
            if (s2 <= s1)
            {
                count = count + s1;
            }
            //If not then subtract current's value from next and add this difference
            //Since we have already considered next character in current number increment i to not iterate to
            // next character
            else
            {
                count = count + s2 - s1;
                i++;
            }
        }
        //If str[i] is the last character I am processing then just add it to the result
        else
        {
            count = count + s1;
        }
    }
    return count;
}