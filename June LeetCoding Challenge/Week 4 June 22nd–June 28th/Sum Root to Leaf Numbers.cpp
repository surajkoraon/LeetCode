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
    int total=0;
    void dfs(TreeNode* root, int sum)
    {
        if(!root)
        {
            return;
        }
        else
        {
            sum*=10;
            sum+=root->val;
            dfs(root->left,sum);
            dfs(root->right,sum);
        }
        if(!root->left && !root->right)
            total+=sum;
    }
    int sumNumbers(TreeNode* root) {
        dfs(root,0);
        return total;
    }
};
