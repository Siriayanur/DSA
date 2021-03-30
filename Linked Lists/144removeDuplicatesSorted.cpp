Node *removeDuplicates(Node *head)
{
    // your code goes here
    Node *t1 = head;

    while (t1 != NULL)
    {
        Node *t2 = t1;
        while ((t2->data == t1->data) && t2 != NULL)
        {
            t2 = t2->next;
        }
        t1->next = t2;
        t1 = t1->next;
    }
    return head;
}