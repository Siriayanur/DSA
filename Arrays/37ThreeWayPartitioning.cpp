#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * [....start ....i......end]
 * start = points to the (last + 1)th position of subarray that contains elements < lowBound
 * end = points to the last position of subarray containing only elements > highBound
 * 
 * i --> points to the current element
 * 
 * whenever I find a[i] < low i swap with a[start] so that this ith element gets
 * into its safe place ans inc to start++ && i++
 * 
 * whenever I find  a[i] > high I swap with a[end]
 * so that it goes it correct place and dec to end-- but not update i
 * because we dont know if the current i (after swap with end ) is in its correct position
 *  so we continue with next iteration with same i 
 * 
 * whenever I find that a[i] >= lowBound and a[i] <= higherBound , i simply let that element be 
 * and inc to i++
 * 
*/
class Solution
{
public:
    //Function to partition the array around the range such
    //that array is divided into three parts.
    void threeWayPartition(vector<int> &arr, int a, int b)
    {
        // code here int start =0, end = n - 1;
        int n = arr.size();
        int start = 0, end = n - 1;
        for (int i = 0; i <= end;)
        {
            if (arr[i] < a)
            {
                swap(arr[i++], arr[start++]);
            }
            else if (arr[i] > b)
            {
                swap(arr[i], arr[end--]);
            }
            else
            {
                i++;
            }
        }
    }
};