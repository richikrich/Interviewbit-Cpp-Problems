/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if(A==nullptr && B==nullptr) return true;
    else if(A!=nullptr && B==nullptr || A==nullptr && B!=nullptr) return false;
    else if(A->val==B->val)
    {
        if(isSameTree(A->left,B->left) && isSameTree(A->right, B->right)) return true;
    }
    else return false;
}
