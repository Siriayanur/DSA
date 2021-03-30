#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *move(Node *head)
{
    Node *temp = head;
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *newNode = temp->next;
    temp->next = NULL;
    newNode->next = head;
    return newNode;
}

int main()
{
}