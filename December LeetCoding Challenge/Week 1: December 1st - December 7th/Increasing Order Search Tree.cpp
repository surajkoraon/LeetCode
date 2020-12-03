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
    TreeNode* head1=NULL;
    TreeNode* head=NULL;
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        inorder(root->left);
        if(head)
        {
            head->right=new TreeNode(root->val);
            head=head->right;
        }
        else
        {
            head=new TreeNode(root->val);
            head1=head;
        }
        inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return head1;
    }
};
