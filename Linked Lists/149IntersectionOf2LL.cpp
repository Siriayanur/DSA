#includ < iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *insertNode(Node *head, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        return head;
    }
    Node *newNode = new Node(data);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node *findIntersection(Node *head1, Node *head2)
{
    // Your Code Here
    Node *t1 = head1, *t2 = head2;
    Node *head = NULL;
    while (t1 != NULL && t2 != NULL)
    {
        if (t1->data == t2->data)
        {
            head = insertNode(head, t1->data);
            t1 = t1->next;
            t2 = t2->next;
        }
        else if (t1->data < t2->data)
        {
            t1 = t1->next;
        }
        else
        {
            t2 = t2->next;
        }
    }
    return head;
}