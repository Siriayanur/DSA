#include <iostream>
#include <vector>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{

    //code here
    vector<long long int> result;
    int count = 0;
    long long int prod = 1;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            prod *= nums[i];
        }
        else
        {
            count++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            if (count == 0)
            {
                result.push_back(prod / nums[i]);
            }
            else
            {
                result.push_back(0);
            }
        }
        else
        {
            if (count == 1)
            {
                result.push_back(prod);
            }
            else
            {
                result.push_back(0);
            }
        }
    }
    return result;
}

int main()
{
}