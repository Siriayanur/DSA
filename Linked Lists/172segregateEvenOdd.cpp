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

Node *divide(int N, Node *head)
{
    // code here
    if (head == NULL)
    {
        return head;
    }
    Node *evenH = NULL, *evenT = NULL, *oddH = NULL, *oddT = NULL;
    while (head)
    {

        // Even node
        if (head->data % 2 == 0)
        {
            if (evenH == NULL)
            {
                evenH = evenT = head;
            }
            else
            {
                evenT->next = head;
                evenT = evenT->next;
            }
        }

        //Odd node
        else
        {
            if (oddH == NULL)
            {
                oddH = oddT = head;
            }
            else
            {
                oddT->next = head;
                oddT = oddT->next;
            }
        }
        head = head->next;
    }

    if (evenH != NULL)
    {
        if (oddH != NULL)
        {
            evenT->next = oddH;
            oddT->next = NULL;
        }
        else
        {
            evenT->next = NULL;
        }
        return evenH;
    }
    else
    {
        if (oddH != NULL)
        {
            oddT->next = NULL;
        }
        return oddH;
    }
}