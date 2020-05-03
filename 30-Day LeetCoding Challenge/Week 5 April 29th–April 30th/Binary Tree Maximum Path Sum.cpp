/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int fun(TreeNode* root,int &sol)
    {
        if(!root)
        {
            return 0;
        }
        int left=fun(root->left,sol);
        int right=fun(root->right,sol);
        sol=max(max(left,0)+root->val+max(right,0),sol);
        sol=max(sol,root->val);
        return max(0,max(left,right)+root->val);
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        int x=fun(root,ans);
        return ans;
    }
};