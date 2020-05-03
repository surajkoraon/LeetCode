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
    bool fun(TreeNode* root, int index, vector<int>& arr)
    {
        if(root==NULL || index==arr.size())
            return false;
        if(index==arr.size()-1 && root->right==NULL && root->left==NULL && root->val==arr[index])
            return true;
        if(root->val==arr[index])
        {
            return fun(root->right,index+1,arr)||fun(root->left,index+1,arr);
        }
        return false;
    }
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return fun(root,0,arr);
    }
};