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
    int diff;
    vector<int> dfs(TreeNode* root)
    {
        vector<int> left;
        if(root->left)
            left=dfs(root->left);
        else
            left={root->val,root->val};
        vector<int> right;
        if(root->right)
            right=dfs(root->right);
        else
            right={root->val,root->val};
        int mini=min(left[0],right[0]);
        int maxi=max(left[1],right[1]);
        diff=max(diff,max(abs(root->val-mini),abs(root->val-maxi)));
        return {min(root->val,mini),max(root->val,maxi)};
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return diff;
    }
};
