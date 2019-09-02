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
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    stack<TreeNode* > nodes;
    TreeNode* temp;
    TreeNode* curr=A;
    if(A->right) nodes.push(A->right);
    if(A->left) nodes.push(A->left);
    while(!nodes.empty())
    {
        temp=nodes.top();
        nodes.pop();
        curr->right=temp;
        curr->left=nullptr;
        curr=curr->right;
        if(temp->right) nodes.push(temp->right);
        if(temp->left) nodes.push(temp->left);
    }
    curr->left=nullptr;
    curr->right=nullptr;
    return A;
}
