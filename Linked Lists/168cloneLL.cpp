#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *arb;

    Node(int x)
    {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

//Function to clone a linked list with next and random pointer.
Node *copyList(Node *head)
{
    // Your code here
    Node *temp = head;
    while (temp != NULL)
    {
        Node *newNode = new Node(temp->data);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next->next;
    }

    Node *current = head;
    while (current != NULL)
    {
        if (current->arb != NULL)
            current->next->arb = current->arb->next;

        current = current->next->next;
    }

    current = head;
    Node *newHead = current->next;
    while (current != NULL)
    {
        Node *temp = current->next->next;
        if (current->next->next)
            current->next->next = temp->next;

        current->next = temp;
        current = temp;
    }

    return newHead;
}