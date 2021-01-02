/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* clonedTarget=NULL;
    void dfs(TreeNode* root,int target)
    {
        if(!root)
            return;
        if(root->val==target)
        {
            clonedTarget=root;
            return;
        }
        dfs(root->left,target);
        dfs(root->right,target);
        
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        dfs(cloned,target->val);
        return clonedTarget;
    }
};
