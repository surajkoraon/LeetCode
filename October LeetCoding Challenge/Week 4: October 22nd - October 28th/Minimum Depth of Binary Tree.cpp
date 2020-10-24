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
    int depth=0;
    int BFS(TreeNode* root)
    {
        if(!root)
            return depth;
        queue<TreeNode*> q;
        q.push(root);
        while(1)
        {
            depth++;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                if(!q.front()->left && !q.front()->right)
                {
                    return depth;
                }
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
        }
        return depth;
    }
    int minDepth(TreeNode* root) {
        return BFS(root);
    }
};
