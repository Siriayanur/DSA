#include <bits/stdc++.h>
using namespace std;

void survival(int nDays, int buyUnitFoodPerDay, int spendUnitFoodPerDay)
{

    if ((buyUnitFoodPerDay * 6) < (spendUnitFoodPerDay * 7) && nDays > 6 || (buyUnitFoodPerDay < spendUnitFoodPerDay))
    {
        cout << "NO" << endl;
    }
    else
    {
        int days = (spendUnitFoodPerDay * nDays) / buyUnitFoodPerDay;
        if ((spendUnitFoodPerDay * nDays) % buyUnitFoodPerDay != 0)
        {
            days++;
        }
        cout << "YES : " << days << endl;
    }
}

int main()
{
}
