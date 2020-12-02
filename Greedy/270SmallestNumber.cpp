#include <bits/stdc++.h>
using namespace std;

int smallestNumber(int sumOfDigits, int digits)
{

    //If sum > possible sum for the given digit count
    if (sumOfDigits > 9 * digits)
    {
        return -1;
    }

    if (sumOfDigits == 0)
    {

        return (digits == 1) ? 0 : -1;
    }

    int result = 0;
    sumOfDigits = sumOfDigits - 1;

    int rem;
    for (int i = 0; i < digits; i++)
    {
        if (sumOfDigits > 9)
        {
            rem = 9;
            sumOfDigits -= 9;
        }
        else
        {
            rem = sumOfDigits;
            sumOfDigits = 0;
        }

        result = result + (rem * (int)pow(10, i));
    }
    result += (int)pow(10, digits - 1);
    return result;
}

string smallestNumberStringWay(int sumOfDigits, int digits)
{
    // code here

    if (sumOfDigits > 9 * digits)
    {
        return "-1";
    }

    if (sumOfDigits == 0)
    {

        return (digits == 1) ? "0" : "-1";
    }

    int result = 0;
    sumOfDigits = sumOfDigits - 1;

    int rem;
    for (int i = 0; i < digits; i++)
    {
        if (sumOfDigits > 9)
        {
            rem = 9;
            sumOfDigits -= 9;
        }
        else
        {
            rem = sumOfDigits;
            sumOfDigits = 0;
        }

        result = result + (rem * (int)pow(10, i));
    }
    result += (int)pow(10, digits - 1);

    string resultant = to_string(result);
    return resultant;
}
int main()
{

    cout << smallestNumber(25, 4) << endl;

    return 0;
}