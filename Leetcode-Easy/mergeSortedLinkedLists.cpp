#include <bits/stdc++.h>
using namespace std;
struct ListNode
{

    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
    }
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *head = dummy;

        while (l1 != NULL && l2 != NULL)
        {

            if (l1->val < l2->val)
            {
                dummy->next = l1;
                l1 = l1->next;
            }
            else
            {
                dummy->next = l2;
                l2 = l2->next;
            }
            dummy = dummy->next;
        }

        if (l1 != NULL)
        {
            dummy->next = l1;
        }
        else
        {
            dummy->next = l2;
        }

        return head->next;
    }
};