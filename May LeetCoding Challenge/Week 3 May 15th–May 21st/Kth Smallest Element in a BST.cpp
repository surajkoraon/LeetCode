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
    int sol;
    void inorder(TreeNode* root, int k,int flag)
    {
        if(root==NULL || !flag)
            return;
        inorder(root->left,k,flag);
        count++;
        if(count==k)
        {
            sol=root->val;
            flag=0;
            return;
        }
        inorder(root->right,k,flag);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k,1);
        return sol;
    }
};
