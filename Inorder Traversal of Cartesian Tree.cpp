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

TreeNode* recursiveBuild(int start, int last, vector<int> &A)
{
    vector<int>::iterator itr=max_element(A.begin()+start,A.begin()+last+1);
    TreeNode* root=new TreeNode(*itr); //set the maximum of the array as the root. Now all the elements to its left will form the left subtree and right will form right subtree
    int index=itr-A.begin();
    if(index!=start) root->left=recursiveBuild(start,index-1,A); //Building left subtree
    if(index!=last) root->right=recursiveBuild(index+1,last,A); //Building right subtree
    return root;
}

TreeNode* Solution::buildTree(vector<int> &A) {
    TreeNode* root=recursiveBuild(0,A.size()-1,A);
    return root;
}
