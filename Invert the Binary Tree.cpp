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
TreeNode* Solution::invertTree(TreeNode* A) {
    //if(A==nullptr) return A;
    if(A->left) invertTree(A->left);
    if(A->right) invertTree(A->right);
    TreeNode* temp;
    temp=A->left;
    A->left=A->right;
    A->right=temp;
    return A;
}
