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
    int c=0;
    void dfs(unordered_map<int,int> m,TreeNode* root, int sum,int total)
    {
        if(!root)
            return;
        total+=root->val;
        if(m.find(total-sum)!=m.end())
        {
            c+=m[total-sum];
        }
        m[total]++;
        if(total==sum)
        {
            c++;
        }
        dfs(m,root->left,sum,total);
        dfs(m,root->right,sum,total);
    }
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int,int> m;
        dfs(m,root,sum,0);
        return c;
    }
};