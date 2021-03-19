/*
0 1 6 7 3 5 9 4 2

*/
#include <iostream>
using namespace std;

void swap(char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}
int partition(char a[], int low, int high, char pivot)
{
    int i = low;
    for (int j = low; j < high; ++j)
    {
        if (a[j] < pivot)
        {
            swap(a + i, a + j);
            i++;
        }
        else if (a[j] == pivot)
        {
            swap(a + high, a + j);
            j--;
        }
    }
    swap(a + high, a + i);
    return i;
}

void quickMatch(char nuts[], char bolts[], int low, int high)
{
    if (low < high)
    {
        int rnd_pivot = (low + rand()) % (high + 1);
        int nut_pivot_indx =
            partition(nuts, low, high, bolts[rnd_pivot]);
        partition(bolts, low, high, nuts[nut_pivot_indx]);
        quickMatch(nuts, bolts, low, nut_pivot_indx - 1);
        quickMatch(nuts, bolts, nut_pivot_indx, high);
    }
}
void matchPairs(char nuts[], char bolts[], int n)
{
    // code here
    srand(time(NULL));
    quickMatch(nuts, bolts, 0, n - 1);
}