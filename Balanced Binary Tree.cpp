#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

#define div 1000000007;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

///Note that every subtree must also be height balanced!!!

int treeHeight(TreeNode *A)
{
    if(A==nullptr) return 0;
    else return max(treeHeight(A->left),treeHeight(A->right))+1;
}

int Solution::isBalanced(TreeNode* A) {
    if(A==nullptr) return 1;
    int leftHeight=treeHeight(A->left);
    int rightHeight=treeHeight(A->right);
    //cout<<leftHeight<<" "<<rightHeight<<endl;
    if(abs(leftHeight-rightHeight)<=1 && isBalanced(A->left)==1 && isBalanced(A->right)==1) return 1;
    else return 0;
}
