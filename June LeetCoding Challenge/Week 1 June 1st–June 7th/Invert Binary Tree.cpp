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
    TreeNode* tree=new TreeNode();
    void dfs(TreeNode* head,TreeNode* root)
    {
        if(root->left)
        {
            head->right=new TreeNode(root->left->val);
            dfs(head->right,root->left);
        }
        if(root->right)
        {
            head->left=new TreeNode(root->right->val);
            dfs(head->left,root->right);
        }
        
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        tree->val=root->val;
        TreeNode* head=tree;
        dfs(head,root);
        return tree;
    }
};
