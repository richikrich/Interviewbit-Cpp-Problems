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
bool search(TreeNode* A, int B, vector<int> &vect)
{
    if(!A) return false;
    vect.push_back(A->val);
    if(A->val==B) return true;
    else if(search(A->left,B,vect)) return true;
    else if(search(A->right,B,vect)) return true;
    else
    {
        vect.pop_back();
        return false;
    }
}

int Solution::lca(TreeNode* A, int B, int C) {
    bool one, two;
    vector<int> vectOne, vectTwo;
    one=search(A,B,vectOne);
    two=search(A,C,vectTwo);
    if(!one || !two) return -1;
    int i=0, j=0;
    while(i<vectOne.size() && j<vectTwo.size() && vectOne[i]==vectTwo[j])
    {
        i++;
        j++;
    }
    return vectOne[i-1];
}
