#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

/*Q: Given an array where elements are sorted in ascending order, convert it to a height balanced BST.*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* midToRoot(int start, int last, const vector<int> &A)
{
    if (start<=last)
    {
        int mid=(start+last)/2;
        TreeNode* root=new TreeNode(A[mid]);
        root->left=midToRoot(start,mid-1,A);
        root->right=midToRoot(mid+1,last,A);
        return root;
    }
    else return nullptr;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    TreeNode* root=midToRoot(0,A.size()-1,A);
    return root;
}
