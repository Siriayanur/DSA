#include <iostream>
#include <queue>
using namespace std;

// void maxSubarray(int *input, int n, int k)
// {

//     int currentMax = max(input[0], max(input[1], input[2]));
//     priority_queue<int> pq;

//     for (int i = 0; i <= n - k; i++)
//     {
//         int j = 0;
//         while (j < k)
//         {
//             pq.push(input[i]);
//             pq.push(input[i + 1]);
//             pq.push(input[i + 2]);
//             j++;
//         }
//         cout << pq.top() << " ";
//         pq = priority_queue<int>();
//     }
// }

// int main()
// {
//     // int n;
//     // cin >> n;
//     // int *a = new int[n];
//     // for (int i = 0; i < n; i++){
//     //     cin >> a[i];
//     // }
//     int a[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
//     maxSubarray(a, 9, 3);
// }
void maxSubarray(int *input, int n, int k)
{

    priority_queue<int> pq;

    for (int i = 0; i <= n - k; i++)
    {
        int j = 0;
        while (j < k)
        {
            pq.push(input[i]);
            pq.push(input[i + 1]);
            pq.push(input[i + 2]);
            j++;
        }
        cout << pq.top() << " ";
        pq = priority_queue<int>();
    }
}

int main()
{
    //code
    int t, n, k;
    while (t > 0)
    {

        cin >> n;
        cin >> k;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        maxSubarray(a, n, k);
        delete a;
        t--;
    }
    return 0;
}