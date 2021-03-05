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
    vector<double> v;
    void bfs(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            double count=0;
            double sum=0;
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                count++;
                sum+=node->val;
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            v.push_back(sum/count);
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        bfs(root);
        return v;
    }
};
