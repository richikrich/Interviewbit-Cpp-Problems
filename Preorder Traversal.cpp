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
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> ret;
    stack<TreeNode* > nodes;
    TreeNode* temp;
    nodes.push(A);
    while(!nodes.empty())
    {
        temp=nodes.top();
        ret.push_back(temp->val);
        nodes.pop();
        if(temp->right) nodes.push(temp->right);
        if(temp->left) nodes.push(temp->left);
    }
    return ret;
}
