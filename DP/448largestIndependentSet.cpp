#include<iostream>
#include<map>
using namespace std;

/*
    To return the max of (consider_root + consider_one_level_after_its_children),(consider_root_left + consider_root_right);
    Recursive solution
*/
int solve(Node* root){
    if(!root){
        return 0;
    }
    int consider_root = 1;
    if(root->left){
        consider_root += (solve(root->left->left) + solve(root->left->right));
    }
    if(root->right){
        consider_root += (solve(root->right->left) + solve(root->right->right));
    }
    int without_consider_root = solve(root->left) +  solve(root->right) ;
                                    
    return max(consider_root,without_consider_root);
}

/**
 * Memoized version
*/
map<int, int> t;
int solveMemoized(Node *root)
{
    if(!root){
        return 0;
    }
    if(t.find(root->data)!= t.end()){
        return t[root->data];
    }
    int consider_root = 1;
    if(root->left){
        //skip the left child level
        consider_root += (solve(root->left->left) + solve(root->left->right));
    }
    if(root->right){
        //skip the right child level

        consider_root += (solve(root->right->left) + solve(root->right->right));
    }
    int without_consider_root = solve(root->left) +  solve(root->right) ;
                                    
    return t[root->data] = max(consider_root,without_consider_root);
}

int LISS(Node *root)
{
    //Code here
    return solve(root);
     
}