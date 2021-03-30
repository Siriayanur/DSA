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

//Function to check whether the list is palindrome.

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *smallAns = reverse(head->next);
    Node *tail = head->next;
    tail->next = head;
    head->next = NULL;
    return smallAns;
}

bool isPalindrome(Node *head)
{
    //Your code here
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    int mid;
    if (count % 2)
    {
        mid = count / 2 + 1;
    }
    else
    {
        mid = count / 2;
    }

    temp = head;
    while (mid > 1)
    {
        mid--;
        temp = temp->next;
    }

    Node *head2 = reverse(temp->next);
    temp->next = NULL;
    Node *head1 = head;

    if (!(count % 2))
    {
        while (head1 != NULL && head2 != NULL && head1->data == head2->data)
        {
            head1 = head1->next;
            head2 = head2->next;
        }
        if (head1 == NULL && head2 == NULL)
            return true;
        else
            return false;
    }
    else
    {
        while (head2 != NULL && head1->data == head2->data)
        {
            head1 = head1->next;
            head2 = head2->next;
        }

        if (head2 == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
