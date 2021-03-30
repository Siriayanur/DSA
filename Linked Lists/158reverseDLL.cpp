#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};
// Similar to SLL
Node *reverseDLL(Node *head)
{
    //Your code here
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *smallAns = reverseDLL(head->next);
    Node *tail = head->next;
    tail->next = head;
    head->prev = tail;
    head->next = NULL;
    smallAns->prev = NULL;
    return smallAns;
}