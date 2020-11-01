/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ret; bool found=false;
    if(A==nullptr || A->val==B) return ret;
    vector<TreeNode* > nodes, temp;
    nodes.push_back(A);
    //temp.push_back(A);
    while(nodes.size()>0)
    {
        for(int i=0; i<nodes.size(); i++)
        {
            if((nodes[i]->left && nodes[i]->left->val==B) || (nodes[i]->right && nodes[i]->right->val==B)) found=true;
            else
            {
                if(nodes[i]->left)
                {
                    temp.push_back(nodes[i]->left);
                    ret.push_back(nodes[i]->left->val);
                }
                if(nodes[i]->right)
                {
                    temp.push_back(nodes[i]->right);
                    ret.push_back(nodes[i]->right->val);
                }
            }
        }
        if(found) return ret;
        else
        {
            nodes=temp;
            temp.clear();
            ret.clear();
        }
    }
    
    return ret;
}
