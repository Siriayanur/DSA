#include <bits/stdc++.h>
using namespace std;

class Triplet
{
public:
    int i;     // Array number in the List of arrays
    int j;     // Index of it in the Array
    int value; // Value it holds
};

class Compare
{
public:
    bool operator()(Triplet a, Triplet b)
    {
        return a.value > b.value;
    }
};

vector<int> kSortedArraysMerge(vector<vector<int> *> input)
{

    vector<int> result;

    priority_queue<Triplet, vector<Triplet>, Compare> pq;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i]->size() > 0)
        {
            int j = 0;
            Triplet b;
            b.i = i;
            b.value = input[i]->at(j);
            b.j = 0;
            pq.push(b);
        }
    }

    for (int i = 0; !pq.empty(); i++)
    {
        Triplet a = pq.top();
        pq.pop();
        result.push_back(a.value);
        int newIndex = a.j + 1;

        if (newIndex < input[a.i]->size())
        {
            Triplet nextElement;
            nextElement.i = a.i;
            nextElement.j = newIndex;
            nextElement.value = input[nextElement.i]->at(newIndex);
            pq.push(nextElement);
        }
    }
    return result;
}

// Without using STL

typedef pair<int, pair<int, int>> pq;
int *mergeKArrays(int **arr, int k)
{
    int *res = new int[k * k];
    priority_queue<pq, vector<pq>, greater<pq>> q;
    for (int i = 0; i < k; i++)
    {
        q.push(make_pair(arr[i][0], make_pair(i, 0)));
    }
    int j = 0;
    while (!q.empty())
    {

        pq curr = q.top();
        q.pop();
        res[j++] = curr.first;
        int iarr = curr.second.first;
        int iele = curr.second.second;
        if (iele < k - 1)
        {
            q.push(make_pair(arr[iarr][iele + 1], make_pair(iarr, iele + 1)));
        }
    }
    return res;
}

int main()
{
}