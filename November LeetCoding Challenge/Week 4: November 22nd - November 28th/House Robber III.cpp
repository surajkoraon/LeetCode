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
    int rob(TreeNode* root) {
        vector<int> v=dfs(root);
        return max(v[0],v[1]);
    }
    vector<int> dfs(TreeNode* root)
    {
        if(!root)
            return {0,0};
        vector<int> left=dfs(root->left);
        vector<int> right=dfs(root->right);
        vector<int> v;
        v.push_back(left[1]+right[1]+root->val);
        v.push_back(max(left[0],left[1])+max(right[0],right[1]));
        return v;
    }
};
