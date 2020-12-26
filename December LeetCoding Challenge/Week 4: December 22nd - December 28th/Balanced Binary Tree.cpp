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
    bool flag=true;
    bool flag1=true;
    int helper(TreeNode* root)
    {
        if(!flag)
            return 0;
        if(!root)
            return 0;
        int left=helper(root->left)+1;
        int right=helper(root->right)+1;
        flag=abs(left-right)<=1;
        if(!flag)
            flag1=flag;
        return max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        helper(root);
        return flag1;
    }
};
