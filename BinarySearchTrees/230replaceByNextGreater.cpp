#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insert(Node *root, int data, Node *&succ)
{
    if (root == NULL)
    {
        return new Node(data);
    }
    if (data < root->data)
    {
        succ = root;
        root->left = insert(root->left, data, succ);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data, succ);
    }
    return root;
}

void replace(int *arr, int n)
{

    Node *root = NULL;
    for (int i = n - 1; i >= 0; i--)
    {
        Node *succ = NULL;
        root = insert(root, arr[i], succ);
        if (!succ)
            arr[i] = -1;
        else
        {
            arr[i] = succ->data;
        }
    }
}

int main()
{
    int n;

    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    replace(arr, n);
    // change(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}