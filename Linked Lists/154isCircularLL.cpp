#include <iostream>
using namespace std;

bool isCircular(Node *head)
{
    // Your code here
    Node *start = head;
    Node *temp = head;
    while (temp->next != NULL && temp->next != start)
    {

        temp = temp->next;
    }

    if (temp->next == start)
        return true;
    else
        return false;
}