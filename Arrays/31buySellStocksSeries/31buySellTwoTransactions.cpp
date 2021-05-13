#include <iostream>
#include <climits>

using namespace std;

int main()
{

    int n;
    cin >> n;
    int prices[n];
    int store1[n] = { 0 } int store2[n] = {0};
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    int minVal = prices[0];
    int profitIfSoldToday = 0;

    for (int i = 1; i < n; i++)
    {
        if (prices[i] < minVal)
            minVal = prices[i];

        profitIfSoldToday = max(store1[i - 1], prices[i] - minVal);
        store1[i] = profitIfSoldToday;
    }

    int maxVal = prices[n - 1]; //55
    int profitIfBoughtToday = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (prices[i] > maxVal) //50
            maxVal = prices[i];
        profitIfBoughtToday = max(store2[i + 1], maxVal - prices[i]);
        store2[i] = profitIfBoughtToday;
    }
    for (int i = 0; i < n; i++)
        cout << store1[i] << " ";

    cout << endl;
    for (int i = 0; i < n; i++)
        cout << store2[i] << " ";

    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        answer = max(answer, store1[i] + store2[i]);
    }
    cout << answer << endl;
    return 0;
}