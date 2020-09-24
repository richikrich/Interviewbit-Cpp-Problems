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

void verticalNodes(TreeNode* root, map<int, vector<int>> &myMap, int counter)
{
    if(!root) return;
    myMap[counter].push_back(root->val);
    verticalNodes(root->left, myMap, counter-1);
    verticalNodes(root->right, myMap, counter+1);
}

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector<vector<int>> ret;
    map<int, vector<int>> myMap;
    int counter=0;
    verticalNodes(A,myMap, counter);
    for(auto itr=myMap.begin(); itr!=myMap.end(); itr++)
        ret.push_back(itr->second);
    return ret;
}
