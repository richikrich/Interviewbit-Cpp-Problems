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

bool isleftSmall(TreeNode* A, int B)
{
    if(A==nullptr) return true;
    if(A->val<B && isleftSmall(A->left,B) &&isleftSmall(A->right,B)) return true;
    else return false;
}

bool isrightBig(TreeNode* A, int B)
{
    if(A==nullptr) return true;
    if(A->val>=B && isrightBig(A->left,B) &&isrightBig(A->right,B)) return true;
    else return false;
}

int Solution::isValidBST(TreeNode* A) {
    if(A==nullptr) return 1;
    //we need to check if all elements on the left subtree are smaller than root
    //and those on the right are greater
    if(isleftSmall(A->left,A->val) && isrightBig(A->right,A->val) && isValidBST(A->left) && isValidBST(A->right)) return 1;
    else return 0;
}
