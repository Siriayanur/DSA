#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *compute(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *smallAns = compute(head->next);
    if (smallAns->data > head->data)
    {
        return smallAns;
    }
    else
    {
        head->next = smallAns;
        return head;
    }
}

//This doesnot work : needs some edge case modification
Node *computeBakwaas(Node *head)
{
    // your code goes here
    if (!head || !head->next)
    {
        return head;
    }
    Node *current = head;
    Node *newHead = current;
    Node *newTail = current;

    while (current->next != NULL)
    {
        if (current->data < current->next->data)
        {
            if (newHead == current)
            {
                newHead = current->next;
                newTail = current->next;
            }
        }
        else
        {
            if (newTail != current)
            {
                newTail->next = current;
                newTail = newTail->next;
            }
        }
        current = current->next;
    }

    if (newTail != current)
        newTail->next = current;
    return newHead;
}