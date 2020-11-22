#include <iostream>
#include <climits>
using namespace std;

// 1 2 -3 -5 4 9

/*
1. All positive  --> If(zeroes){ exclude } -> Multiply all
2. Even Negative numbers ---> If(zeroes) { exclude }  -> Multiply all
3. Odd Negative numbers ---> Track the negative number with least absolute value --> Multiply all
                        ---> At the end divide this maxNegative with the product obtained to cancel its inclusion
4. If (one negative and rest all 0s) || (numberOfZeroes == n)  ---> Return 0

*/
int maxProductSubset(int a[], int n)
{

    if (n == 1)
    {
        return a[0];
    }

    int product = 1;
    int count_negative = 0, count_zeroes = 0, max_negative = INT_MIN;
    for (int i = 0; i < n; i++)
    {

        if (a[i] == 0)
        {
            count_zeroes++;
            continue;
        }

        if (a[i] < 0)
        {
            count_negative++;
            max_negative = max(max_negative, a[i]);
        }
        product *= a[i];
    }

    if (count_zeroes == n)
    {
        return 0;
    }

    //Check for negative number of zeroes
    if (count_negative & 1)
    {
        if (count_zeroes == n - 1 && count_negative == 1)
            return 0;

        product /= max_negative;
    }
    return product;
}

int main()
{
}