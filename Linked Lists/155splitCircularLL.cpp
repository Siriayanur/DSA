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
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    if (head->next == head)
    {
        *head1_ref = head;
        return;
    }
    Node *temp = head, *start = head;
    int count = 0;
    while (temp->next != start)
    {
        count++;
        temp = temp->next;
    }

    count = count + 1;
    int mid;

    if (count % 2)
        mid = count / 2 + 1;
    else
        mid = count / 2;

    temp = head;
    while (mid > 1)
    {
        temp = temp->next;
        mid--;
    }

    Node *head2 = temp->next;
    while (head2->next != start)
        head2 = head2->next;

    head2->next = temp->next;
    *head2_ref = temp->next;

    temp->next = start;
    *head1_ref = start;
}