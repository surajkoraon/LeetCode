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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> sol;
        if(!root)
            return sol;
        vector<int> v;
        int a=1,b=0,c=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            b++;
            TreeNode* temp=q.front();
            v.push_back(temp->val);
            q.pop();
            if(temp->left)
            {
                q.push(temp->left);
                c++;
            }
            if(temp->right)
            {
                q.push(temp->right);
                c++;
            }
            if(a==b)
            {
                sol.push_back(v);
                v.clear();
                a=c;
                b=0;
                c=0;
            }
        }
        reverse(sol.begin(),sol.end());
        return sol;
    }
};
