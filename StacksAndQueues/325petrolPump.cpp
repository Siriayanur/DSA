#include <iostream>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[], int n)
{
    //Your code here
    int start = 0, end = 1;
    int current_petrol = p[start].petrol - p[start].distance;

    while (start != end || current_petrol < 0)
    {

        while (current_petrol < 0 && start != end)
        {

            current_petrol = current_petrol - (p[start].petrol - p[start].distance);
            start = (start + 1) % n;

            // End up in the original starting point means there cannot be any start point
            if (start == 0)
                return -1;
        }
        current_petrol = current_petrol + (p[end].petrol - p[end].distance);
        end = (end + 1) % n;
    }

    return start;
}