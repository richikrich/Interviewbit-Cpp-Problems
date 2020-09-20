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
int Solution::kthsmallest(TreeNode* A, int B) {
    stack<TreeNode* > counter;
    int k=B;
    TreeNode* top=A;
    TreeNode* ret;
    //counter.push();
    ///Basically we are doing in-order traversal, which in a BST ought to return sorted array.
    ///However here we maintain a counter 'k', to check when we have found the required elements.
    while(k>0 && (top || !counter.empty()))
    {
        //top=counter.top();
        while(top)
        {
            counter.push(top);
            top=top->left;
        }
        //top=counter.top();
       ret=counter.top();
       k--;
       top=ret->right;
       counter.pop();
    }
    return ret->val;
}
