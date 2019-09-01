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

 bool isInTree(TreeNode* A, int key) //Checks if a given key exists in the tree
 {
    if(A==nullptr) return false;
    if(A->val==key) return true;
    else if(isInTree(A->left,key) || isInTree(A->right, key)) return true;
    else return false;
 }

int Solution::lca(TreeNode* A, int B, int C) {
    if(!isInTree(A,B)||!isInTree(A,C)) return -1; //if either of the numbers don't exist in the tree
    TreeNode* temp=A; //first common ancestor
    while((isInTree(temp->left,B)&&isInTree(temp->left,C))||(isInTree(temp->right,B)&&isInTree(temp->right,C)))
    {
        if(isInTree(temp->left,B)&&isInTree(temp->left,C)) temp=temp->left; //if both exist in left subtree
        else if(isInTree(temp->right,B)&&isInTree(temp->right,C)) temp=temp->right; //if both exist in right subtree
    }
    return temp->val;
}
