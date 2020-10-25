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

vector<int> Solution::recoverTree(TreeNode* A) {
    stack<TreeNode* > st;
    TreeNode* top=A;
    int prev=INT_MIN, curr;
    vector<int> elements;
    while(top || !st.empty())
    {
        while(top)
        {
            st.push(top);
            top=top->left;
        }
        top=st.top();
        curr=top->val;
        top=top->right;
        if(curr<prev)
        {
            elements.push_back(prev);
            elements.push_back(curr);
        }
        prev=curr;
        st.pop();
    }
    //for(int i=0; i<elements.size(); i++) cout<<elements[i]<<" ";
    //cout<<endl;
    vector<int> ret;
    ret={elements[elements.size()-1], elements[0]};
    return ret;
}
