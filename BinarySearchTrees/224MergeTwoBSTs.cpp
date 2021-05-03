#include <structureBT.h>
/** Two approaches discussed :
 *  1. Traverse both the trees  one after another in inorder fashion and store values in  
 *     a vector. Later sort this vector and return
 *  1a. Store the inorder traversals in 2 separate arrays and merge them using merge()
 *  
 *  2. Perform inorder traversal iteratively of both trees in 2 stacks
 *      Compare the top of stacks and in the one which has lesser value, continue inorder iterative traversal of that 
 */

class Solution
{
public:
    // Return a integer of integers having all the nodes in both the BSTs in a sorted order.

    void inorder(Node *root, vector<int> &result)
    {
        if (!root)
            return;

        inorder(root->left, result);
        result.push_back(root->data);
        inorder(root->right, result);
    }
    //o(m+n)space
    vector<int> merge1(Node *root1, Node *root2)
    {
        //Your code here
        vector<int> result;
        inorder(root1, result);
        inorder(root2, result);
        sort(result.begin(), result.end());
        return result;
    }

    //o(h1 +h2)space
    vector<int> merge2(Node *root1, Node *root2)
    {
        stack<Node *> s1, s2;
        vector<int> result;

        Node *temp = root1;
        while (temp)
        {
            s1.push(temp);
            temp = temp->left;
        }
        temp = root2;
        while (temp)
        {
            s2.push(temp);
            temp = temp->left;
        }

        while (!s1.empty() && !s2.empty())
        {
            //Compare
            Node *current;
            if (s1.top()->data < s2.top()->data)
            {

                current = s1.top();
                s1.pop();
                result.push_back(current->data);
                current = current->right;
                while (current)
                {
                    s1.push(current);
                    current = current->left;
                }
            }
            else
            {
                current = s2.top();
                s2.pop();
                result.push_back(current->data);
                current = current->right;
                while (current)
                {
                    s2.push(current);
                    current = current->left;
                }
            }
        }

        while (!s1.empty())
        {
            Node *cur = s1.top();
            s1.pop();
            result.push_back(cur->data);
            cur = cur->right;
            while (cur)
            {
                s1.push(cur);
                cur = cur->left;
            }
        }
        while (!s2.empty())
        {
            Node *cur = s2.top();
            s2.pop();
            result.push_back(cur->data);
            cur = cur->right;
            while (cur)
            {
                s2.push(cur);
                cur = cur->left;
            }
        }
        return result;
    }
};