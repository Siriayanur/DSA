#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
    Node *prev;
    Node(char data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Correct Sol within Time Bounds
string firstNonRep(string A)
{
    string result = "";
    queue<char> pq;
    int repeated[26] = {0};
    for (int i = 0; i < A.length(); i++)
    {
        pq.push(A[i]);
        repeated[A[i] - 'a']++;
        while (!pq.empty())
        {
            if (repeated[pq.front() - 'a'] > 1)
                pq.pop();
            else
                break;
        }
        if (pq.empty())
            result += "#";
        else
            result += pq.front();
    }
    return result;
}
//End Of Optimised Solution

/* Giving TLE But correct */
void insert(Node **head, Node **tail, char data)
{
    Node *temp = new Node(data);
    if (*head == NULL)
    {
        *head = temp;
        *tail = temp;
    }
    else
    {
        (*tail)->next = temp;
        temp->prev = *tail;
        *tail = temp;
    }
}
void deleteNode(Node **head, Node **tail, Node *temp)
{
    if (*head == NULL)
    {
        return;
    }

    if (*head == temp)
    {
        *head = (*head)->next;
        //  cout << "This";
    }

    if (*tail == temp)
        *tail = (*tail)->prev;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
}
string FirstNonRepeating(string A)
{
    // Code here
    bool repeated[26];
    Node *inDLL[26];
    Node *head = NULL, *tail = NULL;

    for (int i = 0; i < 26; i++)
    {
        inDLL[i] = NULL;
        repeated[i] = false;
    }

    string result = "";
    for (int i = 0; i < A.length(); i++)
    {
        int current = A[i] - 'a';

        if (!repeated[current])
        {

            if (inDLL[current] == NULL)
            {
                insert(&head, &tail, A[i]);
                inDLL[current] = tail;
            }

            else
            {
                deleteNode(&head, &tail, inDLL[current]);
                inDLL[current] = NULL;
                repeated[current] = true;
            }
        }
        if (head != NULL)
        {
            result = result + head->data;
        }
        else
        {
            result = result + "#";
        }
    }

    return result;
}
