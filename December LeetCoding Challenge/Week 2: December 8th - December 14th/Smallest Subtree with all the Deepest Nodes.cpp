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
    TreeNode* sol=NULL;
    int maxHeight=0;
    int postorder(TreeNode* root,int level)
    {
        if(!root)
            return level;
        maxHeight=max(++level,maxHeight);
        int left=postorder(root->left,level);
        int right=postorder(root->right,level);
        if(left==right && left==maxHeight)
            sol=root;
        return max(left,right);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        postorder(root,0);
        return sol;
    }
};
