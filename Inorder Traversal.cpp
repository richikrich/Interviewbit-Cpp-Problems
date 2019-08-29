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

vector<int> Solution::inorderTraversal(TreeNode* A) {
    stack<TreeNode* > nodes;
    TreeNode* curr=A;
    vector<int> ret;
    while(!nodes.empty() || curr)
    {
        while(curr)
        {
            nodes.push(curr);
            curr=curr->left;
        }
        curr=nodes.top();
        nodes.pop();
        ret.push_back(curr->val);
        curr=curr->right;
    }
    return ret;
}
