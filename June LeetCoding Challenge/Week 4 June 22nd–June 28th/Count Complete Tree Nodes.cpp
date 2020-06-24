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
    int count=0;
    void dfs(TreeNode* root)
    {
        if(!root)
            return;
        count++;
        dfs(root->left);
        dfs(root->right);
    }
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return 1;
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};