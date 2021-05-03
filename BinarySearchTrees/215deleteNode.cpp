#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
                                                                                                                                                                                                  *
};

class Solution
{
public:
    TreeNode *getInorderSuccessor(TreeNode *root)
    {
        while (root && root->left)
        {
            root = root->left;
        }
        return root;
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
            return NULL;

        if (key < root->val)
            root->left = deleteNode(root->left, key);

        else if (key > root->val)
            root->right = deleteNode(root->right, key);

        else
        {

            // Leaf Node
            if (!root->left && !root->right)
                return NULL;
            // Only right subtree
            else if (!root->left && root->right)
            {
                TreeNode *temp = root->right;
                delete (root);
                return temp;
            }
            // only left subtree
            else if (!root->right && root->left)
            {
                TreeNode *temp = root->left;
                delete (root);
                return temp;
            }
            // Both left and right subtrees are present
            else
            {
                TreeNode *temp = getInorderSuccessor(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }
        return root;
    }
};