#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};
int findAncestor(unordered_map<int, int> &anc, Node *root, int targetNodeVal, int k)
{
    anc[root->data] = -1;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front->left)
        {
            anc[front->left->data] = front->data;
            q.push(front->left);
        }
        if (front->right)
        {
            anc[front->right->data] = front->data;
            q.push(front->right);
        }
    }
    int count = 0;
    while (anc.find(targetNodeVal) != anc.end() && targetNodeVal != -1)
    {
        targetNodeVal = anc[targetNodeVal];
        count++;
        if (count == k)
            break;
    }
    return targetNodeVal;
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    unordered_map<int, int> anc;
    return findAncestor(anc, root, node, k);
}

/*
This worked only in GFG

int length(Node* root){
    if(root == NULL)
        return 0;
   
    return 1 + length(root->left) + length(root->right);
}

    int findAncestor(int anc[],Node* root,int targetNodeVal,int k){
    anc[root->data] = -1;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *front = q.front();
        q.pop();
        
        if(front->left){
            anc[front->left->data] = front->data;
            q.push(front->left);
        }
        if(front->right){
            anc[front->right->data] = front->data;
            q.push(front->right);
        }
    }
    int count = 0;
    while(targetNodeVal != -1){
        targetNodeVal = anc[targetNodeVal];
        count++;
        if(count == k)
            break;
      
    }
    return targetNodeVal;
}


int kthAncestor(Node *root, int k, int node)
{
    // Code here
    // unordered_map<int,int> anc;
    int n = length(root);
    int anc[n+1]= {0};
    return findAncestor(anc,root,node,k);
}



*/