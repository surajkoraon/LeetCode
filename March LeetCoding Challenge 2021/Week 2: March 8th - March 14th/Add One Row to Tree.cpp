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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1)
        {
            TreeNode* node=new TreeNode(v,root,NULL);
            return node;
        }
        int depth=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            depth++;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(depth==d-1)
                {
                    node->left=new TreeNode(v,node->left,NULL);
                    node->right=new TreeNode(v,NULL,node->right);
                }
                else
                {
                    if(node->left)
                        q.push(node->left);
                    if(node->right)
                        q.push(node->right);
                }
            }
            if(depth==d-1)
                return root;
        }
        return NULL;
    }
};
