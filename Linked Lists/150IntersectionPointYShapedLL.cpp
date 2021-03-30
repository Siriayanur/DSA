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

Node *travel(Node *head, int count)
{
    while (count && head)
    {
        head = head->next;
        count--;
    }
    return head;
}

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node *head1, Node *head2)
{
    // Your Code Here
    int count1 = 0, count2 = 0;
    Node *temp1 = head1, *temp2 = head2;
    while (temp1 != NULL)
    {
        temp1 = temp1->next;
        count1++;
    }
    while (temp2 != NULL)
    {
        temp2 = temp2->next;
        count2++;
    }
    temp1 = head1;
    temp2 = head2;
    int count = abs(count1 - count2);

    if (count1 > count2)
    {
        temp1 = travel(temp1, count);
    }
    else
    {
        temp2 = travel(temp2, count);
    }
    while (temp1 != temp2 && temp1 && temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if (!temp1 || !temp2)
    {
        return -1;
    }
    return temp1->data;
}