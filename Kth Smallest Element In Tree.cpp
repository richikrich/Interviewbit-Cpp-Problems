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
 /**We perform inorder traversal which will give us the elements in a sorted order and return the required element**/

int Solution::kthsmallest(TreeNode* A, int B) {
    //inorder traversal
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
    return ret[B-1];
}
