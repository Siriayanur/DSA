#include <iostream>
using namespace std;

/**
 *     NULL --> NULL
 *      1  -> 1

 */

class Node
{

public:
    int data;
    Node *left;
    Node *right;
};

void mirrorBinaryTree(Node *root)
{

    //Swap the left and right children and call recursion further

    if (!root)
    {
        return;
    }

    if (!root->left && !root->right)
    {
        return;
    }

    Node *temp = root->left; // 2
    root->left = root->right;
    root->right = temp;
    /*
        1 
      3    2
    7   6  N  4
     

    TEMP    
        
*/
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}

int main()
{
}