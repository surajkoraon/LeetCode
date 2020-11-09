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
    int sum=0;
    int postorder(TreeNode* root)
    {
        if(!root)
            return 0;
        int a=postorder(root->left);
        int b=postorder(root->right);
        sum+=a>b?a-b:b-a;
        return a+b+root->val;
    }
    int findTilt(TreeNode* root) {
        postorder(root);
        return sum;
    }
};
