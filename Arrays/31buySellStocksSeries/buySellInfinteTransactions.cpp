#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int prices[n];
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    int bd = 0;
    int sd = 0;
    int profit = 0;

    for (int i = 1; i < n; i++)
    {
        if (prices[i] > prices[i - 1])
            sd++;

        else
        {
            profit += prices[sd] - prices[bd];
            bd = sd = i;
        }
    }
    profit += prices[sd] - prices[bd];
    cout << profit << endl; // This prints the total max profit of multiple transactions
    return 0;
}