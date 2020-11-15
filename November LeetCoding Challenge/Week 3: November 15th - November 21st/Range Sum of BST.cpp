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
    int sum=0,min,max;
    void dfs(TreeNode* root)
    {
        if(!root)
            return;
        if(root->val>=min && root->val<=max)
            sum+=root->val;
        if(root->val>min)
            dfs(root->left);
        if(root->val<max)
            dfs(root->right);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        min=low;
        max=high;
        dfs(root);
        return sum;
    }
};
