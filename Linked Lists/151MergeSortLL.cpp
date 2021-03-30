#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
int findLength(Node *head)
{

    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

Node *merge(Node *head1, Node *head2)
{
    Node *fhead = NULL;
    Node *ftail = NULL;

    if (head1->data <= head2->data)
    {
        fhead = head1;
        ftail = head1;
        head1 = head1->next;
    }
    else
    {
        fhead = head2;
        ftail = head2;
        head2 = head2->next;
    }

    while (head1 && head2)
    {
        if (head1->data <= head2->data)
        {
            ftail->next = head1;
            ftail = head1;
            head1 = head1->next;
        }
        else
        {
            ftail->next = head2;
            ftail = head2;
            head2 = head2->next;
        }
    }
    if (head1 == NULL)
    {
        ftail->next = head2;
        ftail = head2;
    }
    else if (head2 == NULL)
    {
        ftail->next = head1;
        ftail = head1;
    }
    return fhead;
}

Node *mergeSort(Node *head)
{
    // your code here
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    int length = findLength(head);
    int count = 0;
    Node *head1 = head;

    while (count < (length - 1) / 2)
    {
        head1 = head1->next;
        count++;
    }
    Node *head2 = head1->next;
    head1->next = NULL;

    Node *h1 = mergeSort(head);
    Node *h2 = mergeSort(head2);

    Node *finalHead = merge(h1, h2);
    return finalHead;
}