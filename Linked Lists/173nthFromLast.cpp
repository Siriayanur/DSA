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
int getNthFromLast(Node *head, int n)
{
    // Your code here
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    int target = count - n;
    if (target < 0)
    {
        return -1;
    }
    temp = head;

    while (target > 0)
    {
        target--;
        temp = temp->next;
    }
    return temp->data;
}