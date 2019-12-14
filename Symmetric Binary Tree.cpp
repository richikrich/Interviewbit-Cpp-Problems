#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

#define div 1000000007;

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

///checks if two trees are mirror images of eachother

bool isMirror(TreeNode* A, TreeNode* B)
{
    if(A==nullptr && B==nullptr) return true;
    if(A!=nullptr && B!=nullptr && A->val==B->val)
    {
        if(isMirror(A->left,B->right)==true && isMirror(A->right,B->left)==true) return true;
        else return false;
    }
    return false;
}

int Solution::isSymmetric(TreeNode* A) {
    if(isMirror(A,A)) return 1;
    else return 0;

}
