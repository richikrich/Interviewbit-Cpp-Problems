#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



TreeNode* Solution::flatten(TreeNode* A) {
    /**
        Memory limit was exceeded due to creation of a new tree and returning it, instead of altering the existing tree.
        Might want to just do preorder traversal. Since the right node will be stored in the stack then, we can alter the root
        while preserving the rest of the tree
    **/
    TreeNode* root;
    TreeNode* prev=new TreeNode(0);
    TreeNode* temp;
    TreeNode* curr=A;
    stack<TreeNode* > st;
    root=new TreeNode(0);
    prev->right=root;
    //st.push(curr);
    while(curr || !st.empty())
    {
        while(curr)
        {
            temp=new TreeNode(curr->val);
            root->right=temp;
            st.push(curr);
            root=root->right;
            curr=curr->left;
        }
        curr=st.top();
        curr=curr->right;
        st.pop();
    }

    return prev->right->right;
}
