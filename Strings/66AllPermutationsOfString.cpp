#include <iostream>
using namespace std;

class Solution
{
public:
    void swap(string &input, int i, int j)
    {
        char temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }

    void permutate(string input, int l, int r, vector<string> &finalRes)
    {
        if (l == r)
        {
            finalRes.push_back(input);
        }
        else
        {

            for (int i = l; i <= r; i++)
            {
                swap(input, l, i);
                permutate(input, l + 1, r, finalRes);
                swap(input, l, i);
            }
        }
    }

    vector<string> find_permutation(string S)
    {
        // Code here there
        vector<string> finalRes;
        permutate(S, 0, S.length() - 1, finalRes);
        sort(finalRes.begin(), finalRes.end());
        return finalRes;
    }
};
