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
        The idea is to alter the existing tree while performing in-order traversal, thus saving memory. Since the right nodes are
        already saved in the stack, the rest of the tree is well preserved.
    **/
    TreeNode* curr=A;
    TreeNode* temp;
    stack<TreeNode* > st;
    if(A->right) st.push(A->right);
    if(A->left) st.push(A->left);
    while(!st.empty())
    {
        temp=st.top();
        curr->right=temp;
        curr->left=nullptr;
        curr=curr->right;
        st.pop();
        if(temp->right) st.push(temp->right);
        if(temp->left) st.push(temp->left);
    }

    curr->left=nullptr;
    curr->right=nullptr;

    return A;
}
