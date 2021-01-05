#include <bits/stdc++.h>
using namespace std;

// o(n1+n2+n3) + o(nlogn) time , o(max(n1,n2,n3)) space
vector<int> commonElements(int a[], int b[], int c[], int n1, int n2, int n3)
{
    vector<int> result;
    unordered_map<int, int> ourmap;

    for (int i = 0; i < n1; i++)
    {

        ourmap[a[i]] = 1;
    }
    for (int i = 0; i < n2; i++)
    {
        if (ourmap[b[i]] == 1)
        {
            ourmap[b[i]] = 2;
        }
    }
    for (int i = 0; i < n3; i++)
    {
        if (ourmap[c[i]] == 2)
        {
            ourmap[c[i]] = 3;
        }
    }
    for (auto i : ourmap)
    {
        if (i.second == 3)
        {
            result.push_back(i.first);
        }
    }

    sort(result.begin(), result.end());
    return result;
}

// Approach 2 : o(n) time and o(1) space
int check(int a, int b, int c)
{
    int temp = min({a, b, c});

    if (temp == a)
        return 1;
    else if (temp == b)
        return 2;
    else
        return 3;
}
vector<int> commonElements2(int A[], int B[], int C[], int n1, int n2, int n3)
{
    //code here.
    vector<int> arr1;

    int p1 = 0, p2 = 0, p3 = 0;

    int rec = INT_MIN;

    while (p1 < n1 && p2 < n2 && p3 < n3)
    {
        if (A[p1] == B[p2] && B[p2] == C[p3])
        {
            if (rec != A[p1])
            {
                rec = A[p1];
                arr1.push_back(A[p1]);
            }
            ++p1;
        }
        else
        {
            int choice = check(A[p1], B[p2], C[p3]);

            if (choice == 1)
                ++p1;
            else if (choice == 2)
                ++p2;
            else
                ++p3;
        }
    }

    if (arr1.size() == 0)
        arr1.push_back(-1);

    return arr1;
}

int main()
{

    int a[6] = {1, 2, 3, 4, 7, 8};
    int b[5] = {3, 3, 4, 4, 5};
    int c[6] = {1, 3, 6, 7, 9, 10};
    vector<int> result = commonElements(a, b, c, 6, 5, 6);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}
