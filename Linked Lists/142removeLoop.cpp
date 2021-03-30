#include <iostream>
using namespace std;

class Solution
{
public:
    //Function to remove a loop in the linked list.
    void detectLoop(Node *head)
    {

        Node *fast = head, *slow = head;
        bool isLoop = false;

        while (slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                isLoop = true;
                break;
            }
        }
        if (!isLoop)
            return;

        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        Node *startingNode = slow;
        Node *temp = slow->next;

        while (temp->next != startingNode)
        {

            temp = temp->next;
        }
        temp->next = NULL;
    }

    void removeLoop(Node *head)
    {
        detectLoop(head);
    }
};