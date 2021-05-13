#include <iostream>
using namespace std;
void rightRotate(int a[], int wrongIndex, int index, int n)
{
    int temp = a[index];
    int i;
    for (i = wrongIndex; i < index; i++)
    {
        a[i + 1] = a[i];
    }
    a[0] = temp;
}
void rearrange(int a[], int n)
{
    int wrongIndex = -1;

    for (int i = 0; i < n; i++)
    {
        if (wrongIndex != -1)
        {
            //Now i already have the wrong index, I just need to check if the current index has
            // opposite sign and is also wrong

            if (a[wrongIndex] >= 0 && a[i] < 0 || a[wrongIndex] < 0 && a[i] >= 0)
            {
                rightRotate(a, wrongIndex, i, n);
            }
            //If the difference between the current and wrongIndex is greater than 2
            // It means that there are more elements and we need to check further..
            if (i - wrongIndex >= 2)
                wrongIndex += 2;
            else
                wrongIndex = -1;
        }
        else
        {

            //We need to see if there is an out of place element now :
            if (i % 2 == 0 && a[i] >= 0 || i % 2 != 0 && a[i] < 0)
            {
                wrongIndex = i;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    rearrange(a, n);
}