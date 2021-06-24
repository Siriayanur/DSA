#include<bits/stdc++.h>
using namespace std;


class LRUCache
{

    public:
    
    class Node{
          public:
          int key;
          int val;
          Node* prev;
          Node* next;
          Node(int k,int v){
              key = k;
              val = v;
              prev = NULL;
              next = NULL;
          }
    };
    
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    
    int size;
    unordered_map<int,Node*> store;
    
    LRUCache(int cap)
    {
        // code here
        size = cap;
        head->next = tail;
        tail->prev = head;
    }
    
    //Constructor for initializing the cache capacity with the given value.
    void insertNode(int key,int val){
        
        Node* newNode = new Node(key,val);
        head->next->prev = newNode;
        newNode->next = head->next;
        head->next = newNode;
        newNode->prev = head;
        
        store[key] = head->next;
    }
    
    void deleteNode(Node* temp){
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
    }
    
    
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        if(store.find(key) != store.end()){
            Node* currentNodeAddr = store[key];
            int requiredValue = currentNodeAddr->val;
            store.erase(key);
            deleteNode(currentNodeAddr);
            insertNode(currentNodeAddr->key,currentNodeAddr->val);
            return requiredValue;
        }
        return -1;
    }
    
    
    //Function for storing key-value pair.
    void set(int key, int val)
    {
        // your code here 
        if(store.find(key) != store.end()){
            Node* existingNodeAddr = store[key];
            store.erase(key);
            deleteNode(existingNodeAddr);
            
        }
        if(store.size() == size){
            store.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        insertNode(key,val);
        
    }
};