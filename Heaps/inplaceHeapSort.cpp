#include <bits/stdc++.h>
using namespace std;

void inplaceHeapSort(int *input, int size)
{

    //Heapify the given array
    int minIndex;
    for (int i = 1; i < size / 2; i++)
    {
        int childI = i;
        while (childI > 0)
        {
            int parentI = (childI - 1) / 2;
            //If parent element is larger than the child element : Heapify Upwards
            // We need min Heap
            if (input[parentI] > input[childI])
            {
                int temp = input[parentI];
                input[parentI] = input[childI];
                input[childI] = temp;
            }
            else
            {
                break;
            }
            childI = parentI;
        }
    }

    //Elements of the input array would be arranged in minheap fashion
    // Time to reorder them in decreasing order

    //Plan :
    // Since min Heap always removes minimum element out of the array, we can store that at
    // the last index of the array and reduce the heap size to size--

    while (size > 1)
    {

        int temp = input[0];
        input[0] = input[size - 1];
        input[size - 1] = temp;

        size--;
        //Heapify the new heap
        int parentIndex = 0;
        int leftIndex = 2 * parentIndex + 1;
        int rightIndex = 2 * parentIndex + 2;
        while (leftIndex < size)
        {
            int minIndex = parentIndex;
            if (input[leftIndex] < input[minIndex])
            {
                minIndex = leftIndex;
            }
            if (rightIndex < size && input[rightIndex] < input[minIndex])
            {
                minIndex = rightIndex;
            }
            if (minIndex == parentIndex)
            {
                break;
            }

            int temp = input[minIndex];
            input[minIndex] = input[parentIndex];
            input[parentIndex] = temp;

            parentIndex = minIndex;
            leftIndex = 2 * parentIndex + 1;
            rightIndex = 2 * parentIndex + 2;
        }
    }
}

int main()
{

    int size;
    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    inplaceHeapSort(input, size);

    for (int i = 0; i < size; i++)
        cout << input[i] << " ";

    return 0;
}
