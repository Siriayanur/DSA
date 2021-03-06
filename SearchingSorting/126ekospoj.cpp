#include <bits/stdc++.h>
using namespace std;

bool solve(int a[], int n, int mid, int m)
{

	int wood = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > mid)
			wood += a[i] - mid;
	}
	if (wood >= m)
		return true;
	else
		return false;
}

int32_t main()
{

	int n, m;
	cin >> n >> m;

	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int ub = *max_element(a, a + n);
	int lb = 0;
	int bladeHeight = 0;

	while (lb <= ub)
	{
		int mid = (lb + ub) / 2;

		if (solve(a, n, mid, m))
		{
			bladeHeight = mid;
			lb = mid + 1;
		}
		else
		{
			ub = mid - 1;
		}
	}
	cout << bladeHeight << endl;
	return 0;
}