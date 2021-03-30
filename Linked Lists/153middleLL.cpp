#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *middleNode(ListNode *head)
{
    int count = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
        //1-2-3-4-5-6-7-null
    }

    int mid;
    mid = count / 2 + 1;

    temp = head;
    while (mid > 1)
    {
        temp = temp->next;
        mid--;
    }
    return temp;
}