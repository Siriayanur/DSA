#include <iostream>
using namespace std;

// int t[1001][1001];

int knapsack_top_down(int wt[], int val[], int W, int n)
{
    int t[n + 1][W + 1];

    //Initialisation using recursive base condition
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {

            if (wt[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            }
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][W];
}

void fill()
{

    memset(t, -1, sizeof(t));
}

//memoization
//Run memoized version after uncommenting the global t[][]
int knapsack_memoization(int W, int wt[], int val[], int n)
{

    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (t[n][W] != -1)
    {
        return t[n][W];
    }

    if (wt[n - 1] <= W)
    {
        return t[n][W] = max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1), knapsack(W, wt, val, n - 1));
    }
    else if (wt[n - 1] > W)
    {
        return t[n][W] = knapsack(W, wt, val, n - 1);
    }
}

//
int knapSack(int W, int wt[], int val[], int n)
{
    // Your code here
    fill();

    return knapsack(W, wt, val, n);
}
int main()
{
}