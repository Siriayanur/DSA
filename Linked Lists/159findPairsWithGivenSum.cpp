#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next, *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void pairSum(struct Node *head, int sum)
{
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    Node *temp = head;
    while (temp && tail && temp != tail && tail->next != temp)
    {

        if (temp->data + tail->data == sum)
        {
            cout << temp->data << " " << tail->data << endl;
            temp = temp->next;
            tail = tail->prev;
        }
        else if (temp->data + tail->data < sum)
        {
            temp = temp->next;
        }
        else
        {
            tail = tail->prev;
        }
    }
}