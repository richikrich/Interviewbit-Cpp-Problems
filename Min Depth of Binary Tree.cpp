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
**/

int Solution::minDepth(TreeNode* A) {
    if(A==nullptr) return 0;
    if(A->left==nullptr && A->right==nullptr) return 1;
    if(A->left==nullptr) return (1+minDepth(A->right));
    if(A->right==nullptr) return (1+minDepth(A->left));
    if(A->left!=nullptr && A->right!=nullptr) return (1+min(minDepth(A->left), minDepth(A->right)));
}
