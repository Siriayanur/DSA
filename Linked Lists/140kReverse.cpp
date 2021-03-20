#include <iostream>
using namespace std;

class Pair
{
public:
    node *head;
    node *tail;
};

Pair reverseLL(node *head)
{

    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallRes = reverseLL(head->next);
    smallRes.tail->next = head;
    head->next = NULL;

    Pair ans;
    ans.head = smallRes.head;
    ans.tail = head;
    return ans;
}

node *kReverse(node *head, int n)
{
    //write your code here

    if (head == NULL || head->next == NULL)
        return head;

    int count = 0;
    node *h1 = head;
    while (count < n - 1 && h1->next != NULL)
    {
        h1 = h1->next;
        count++;
    }

    node *h2 = h1->next;
    h1->next = NULL;

    Pair result = reverseLL(head);

    node *smallResult = kReverse(h2, n);

    result.tail->next = smallResult;

    return result.head;
}