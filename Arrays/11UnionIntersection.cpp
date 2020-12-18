#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int intersectionOfTwoArrays(int arr1[], int arr2[], int n, int m)
{
    unordered_map<int, int> mp;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        mp[arr1[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        if (mp.count(arr2[i]) > 0)
        {
            count++;
        }
    }
    return count;
}

int unionOfTwoArrays(int arr1[], int N, int arr2[], int M)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < N; i++)
    {
        mp[arr1[i]]++;
    }

    for (int i = 0; i < M; i++)
    {
        mp[arr2[i]]++;
    }

    //Intersection

    return mp.size();
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;

        int arr1[N];
        for (int i = 0; i < N; i++)
        {
            cin >> arr1[i];
        }

        int arr2[M];
        for (int i = 0; i < M; i++)
        {
            cin >> arr2[i];
        }

        cout << unionOfTwoArrays(arr1, N, arr2, M) << endl;
        cout << intersectionOfTwoArrays(arr1, arr2, N, M) << endl;
        }

    return 0;
}