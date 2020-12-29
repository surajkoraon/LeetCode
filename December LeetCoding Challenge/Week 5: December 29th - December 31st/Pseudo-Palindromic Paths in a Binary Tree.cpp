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
    void dfs(TreeNode* root,vector<int>& v)
    {
        if(!root)
            return;
        v[root->val]^=1;
        if(!root->left && !root->right)
        {
            int temp=0;
            for(int x:v)
            {
                temp+=x;
                if(temp>1)
                    break;
            }
            if(temp<=1)
                count++;
        }
        else
        {
            dfs(root->left,v);
            dfs(root->right,v);
        }
        v[root->val]^=1;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> v(10,0);
        dfs(root,v);
        return count;
    }
};
