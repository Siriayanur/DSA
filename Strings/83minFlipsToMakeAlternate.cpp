#include <iostream>
using namespace std;

int minFlips(string S)
{
    // your code here
    // Try to populate the string to generate both the sequences
    // And only return min(both ways)

    //If you were to generate the sequence 01010101...

    int flips = 0;
    for (int i = 0; i < S.length(); i++)
    {
        if (i % 2 == 0)
            if (S[i] != '0') //0 at even position
                flips++;

            else if (S[i] != '1') // 1 at odd position
                flips++;
    }

    int flips2 = 0;
    for (int i = 0; i < S.length(); i++)
    {
        if (i % 2 == 0)
            if (S[i] != '1') //0 at odd position
                flips2++;

            else if (S[i] != '0') //1 at even position
                flips2++;
    }
    return min(flips, flips2);
}