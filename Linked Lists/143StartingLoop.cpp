class Node
{
    Node *head;
    Node *tail;
    int data;
};

Node *detectLoopStart(Node *head)
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
    return startingNode;
}