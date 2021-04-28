#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{

public:
    /*
        //Function to check if S is a subtree of tree T.
        // The function takes o(m*n) time as we search for the subtree  S in every subtree of T
        // So if the size of the treeT  is m and the size of the tree S is n then the time becomes o(m*N) which is 
        // not acceptable
        
        bool isSame(Node *root1,Node* root2) {
            if(root1 == NULL && root2 == NULL){
                return true
            }
            if(root1->data != root2->data || !root1 && root2 || !root2 && root1) {
                return false;
            }
            isSame(root1->left, root2->left) && isSame(root1->right,root2->right);
        }

*/
    /*
    
        Switching to more optimised solution : : : : )
    */
    void preorder(Node *root, vector<int> &preorderResult)
    {
        if (!root)
        {
            preorderResult.push_back(-1);
            return;
        }
        preorderResult.push_back(root->data);
        preorder(root->left, preorderResult);
        preorder(root->right, preorderResult);
    }

    void inorder(Node *root, vector<int> &inorderResult)
    {
        if (!root)
        {
            inorderResult.push_back(-1);
            return;
        }
        inorder(root->left, inorderResult);
        inorderResult.push_back(root->data);
        inorder(root->right, inorderResult);
    }

    bool checkIfExists(vector<int> &parent, vector<int> &child)
    {
        string s1 = "";
        string s2 = "";
        for (long long int i = 0; i < parent.size(); i++)
        {
            s1 += to_string(parent[i]);
        }

        for (long long int i = 0; i < child.size(); i++)
        {
            s2 += to_string(child[i]);
        }
        if (s1.find(s2) != -1)
        {
            return true;
        }
        return false;
    }

    bool isSubTree(Node *root1, Node *root2)
    {
        // Your code here
        vector<int> inS, inT, preS, preT;

        preorder(root1, preT);
        preorder(root2, preS);
        inorder(root1, inT);
        inorder(root2, inS);
        return checkIfExists(preT, preS) && checkIfExists(inT, inS);
    }
}