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

class Solution
{
public:
    //Function to remove duplicates from unsorted linked list.
    Node *removeDuplicates(Node *head)
    {
        // your code goes here
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        unordered_map<int, int> map;
        Node *temp = head->next;
        Node *prev = head;
        map[prev->data] = 1;

        while (temp != NULL)
        {
            if (map.count(temp->data) > 0)
            {
                prev->next = temp->next;
            }
            else
            {
                map[temp->data]++;
                prev = temp;
            }
            temp = temp->next;
        }
        return head;
    }
};