#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Compare
{
public:
    int operator()(Node *a, Node *b)
    {
        return b->data < a->data;
    }
};

// arr[pointer_to_L1, pointer_to_L2, .., pointer_to_Ln]
// n -> sizeof arr
Node *mergeKSortedLists(Node *input[], int n)
{
    Node *result = NULL;

    priority_queue<Node *, vector<Node *>, Compare> pq;
    for (int i = 0; i < n; i++)
    {
        if (input[i])
        {
            pq.push(input[i]);
        }
    }

    Node *dummy = (Node *)malloc(sizeof(Node));
    Node *tail = dummy;

    while (!pq.empty())
    {
        Node *temp = pq.top();
        pq.pop();
        if (temp->next)
        {
            pq.push(temp->next);
        }
        tail->next = temp;
        tail = tail->next;
    }

    return dummy->next;
}

int main()
{
    return 0;
}