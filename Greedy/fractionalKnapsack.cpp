#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Item
{
public:
    int value, weight;
    Item(int value, int weight)
    {
        this->value = value;
        this->weight = weight;
    }
};

bool Comparator(Item a, Item b)
{

    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, Item input[], int n)
{

    sort(input, input + n, Comparator);
    int curWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (curWeight + input[i].weight <= W)
        {
            curWeight += input[i].weight;
            finalValue += input[i].value;
        }
        else
        {
            int remain = W - curWeight;
            finalValue += input[i].value * ((double)remain / (double)input[i].weight);
            break;
        }
    }
    return finalValue;
}

int main() {}