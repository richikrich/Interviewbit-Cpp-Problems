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
int Solution::maxDepth(TreeNode* A) {
    if(A==nullptr) return 0;
    int leftDepth=maxDepth(A->left);
    int rightDepth=maxDepth(A->right);
    return max(leftDepth,rightDepth)+1;
}
