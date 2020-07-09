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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        int result=0;
        while(!q.empty())
        {
            int size=q.size();
            int n=q.back().second-q.front().second+1;
            result=max(result,n);
            while(size--)
            {
                pair<TreeNode*,int> p=q.front();
                q.pop();
                if(p.first->left)
                    q.push({p.first->left,(long)(p.second)*2});
                if(p.first->right)
                    q.push({p.first->right,1+(long)(p.second)*2});
            }
        }
        return result;
    }
};
