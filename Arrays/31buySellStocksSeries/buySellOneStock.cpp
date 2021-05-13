#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int prices[n];
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    int totalProfit = 0;
    int currentProfit = 0;
    int least = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (prices[i] < least)
        {
            least = prices[i];
        }

        currentProfit = prices[i] - least;
        totalProfit = max(totalProfit, currentProfit);
    }
    cout << totalProfit << endl;
    return 0;
}