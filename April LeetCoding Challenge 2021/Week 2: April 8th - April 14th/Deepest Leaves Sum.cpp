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
    
    int maxDepth=0;
    int ans=0;
    void dfs(TreeNode* root,vector<int>& v,int depth)
    {
        if(!root)
            return;
        if(!root->left && !root->right)
        {
            if(depth==maxDepth)
                ans+=root->val;
            else if(depth>maxDepth)
            {
                ans=root->val;
                maxDepth=depth;
            }
            return;
        }
        if(root->left)
        {
            dfs(root->left,v,depth+1);
        }
        if(root->right)
        {
            dfs(root->right,v,depth+1);
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        vector<int> v(35,0);
        dfs(root,v,0);
        return ans;
    }
};
