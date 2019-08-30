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

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    stack<TreeNode* > node1;
    stack<TreeNode* > node2;
    TreeNode* curr=A;
    //counter=1;
    vector<vector<int> > ret;
    if(A==nullptr) return ret;
    vector<int> temp;
    node1.push(curr);
    bool leftToRight=true;
    while(!node1.empty())
    {
        curr=node1.top();
        node1.pop();
        temp.push_back(curr->val);
        if(leftToRight)
        {
            if(curr->left) node2.push(curr->left);
            if(curr->right) node2.push(curr->right);
        }
        else
        {
            if(curr->right) node2.push(curr->right);
            if(curr->left) node2.push(curr->left);
        }
        if(node1.empty())
        {
            ret.push_back(temp);
            temp.clear();
            leftToRight=!leftToRight;
            swap(node1,node2);
        }
    }
    return ret;
}
