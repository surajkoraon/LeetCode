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
    int index=0;
    bool flag=1;
    vector<int> output;
    void helper(TreeNode* root, vector<int>& voyage)
    {
        if(root->val!=voyage[index])
        {
            flag=0;
            return;
        }
        if(root->left && root->left->val!=voyage[index+1])
        {
            output.push_back(root->val);
            TreeNode* node=root->left;
            root->left=root->right;
            root->right=node;
        }
        if(root->left)
        {
            index++;
            helper(root->left,voyage);
        }
        if(root->right && flag)
        {
            index++;
            helper(root->right,voyage);
        }
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        helper(root,voyage);
        if(!flag)
            return {-1};
        return output;
    }
};
