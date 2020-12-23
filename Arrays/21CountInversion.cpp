#include <bits/stdc++.h>
using namespace std;

long long int inversionCountNaive(long long a[], long long n)
{
    //Brute Force 0(n*n)
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                count++;
            }
        }
    }
    return count;
}

long long merge(long long a[], long long temp[], long long start, long long mid, long long end)
{

    // mid is the start of the 2nd array (subarray)
    //start is the starting of the 1st array
    // end is valid end index of the 2nd subarray
    // mid - 1 will give the valid end index of the first subarray

    long long i, j, k;
    long long inv_count = 0;

    i = start;
    j = mid;

    /* index to push elements to temp array */
    k = start;
    while ((i <= mid - 1) && (j <= end))
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];

            /* make sure to increase the inversion count */
            inv_count = inv_count + (mid - i);
            /* eg: 
                   i     j,mid
            index: 0 1 2 3 4 5
            eleme: 7 8 9 1 2 3 
                    

                 a[i]=7 > a[j]=1
                so 1 is not only lessser than 7 but also
                lesser than all the elements that follow 7 in subarray arr1
                so inv_count + 3 
                why 3? --> mid - i 
            
            */
        }
    }
    while (i <= mid - 1)
    {
        temp[k++] = a[i++];
    }
    while (j <= end)
    {
        temp[k++] = a[j++];
    }
    for (int i = start; i <= end; i++)
    {
        a[i] = temp[i];
    }
    return inv_count;
}

long long mergeSort(long long a[], long long temp[], long long start, long long end)
{
    int mid, inv_count = 0;
    if (start < end)
    {
        mid = (start + end) / 2;
        inv_count += mergeSort(a, temp, start, mid);
        inv_count += mergeSort(a, temp, mid + 1, end);
        inv_count += merge(a, temp, start, mid + 1, end);
    }
}

int main()
{
    long long a[] = {1, 2, 0, 4};
    long long n;
    cin >> n;
    cout << inversionCountNaive(a, 4) << endl;
    long long temp[n];
    int ans = mergeSort(a, temp, 0, n - 1);
    cout << "Number of count Inversions" << ans << endl;
    return 0;
}