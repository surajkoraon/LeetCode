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
    TreeNode* delete_node(TreeNode* root, int low, int high)
    {
        if (root == NULL) 
            return NULL;
        if (root->val > high )
        {
            root =  delete_node(root->left, low, high);
        }
        else if (root->val < low )
        {
            root = delete_node(root->right, low, high);
        }
        else if (root->val >= low && root->val <= high)
        {
            if(root->left && root->right)
            {
                root->right =  delete_node(root->right, low, high);
                root->left = delete_node(root->left, low, high);
            }
            else if (root->right)
            {
                root->right = delete_node(root->right, low, high);
            }
            else
            {
                root->left = delete_node(root->left, low, high);
            }
        }
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return delete_node(root, low, high);
    }
};