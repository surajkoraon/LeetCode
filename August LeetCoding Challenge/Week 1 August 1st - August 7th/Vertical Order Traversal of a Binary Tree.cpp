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
    vector<vector<int>> sol;
    void dfs(map<pair<int,int>,vector<int>> &m,TreeNode* root,int index,int height)
    {
        if(!root)
            return;
        m[{index,height}].push_back(root->val);
        dfs(m,root->left,index-1,height+1);
        dfs(m,root->right,index+1,height+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<pair<int,int>,vector<int>> m;
        dfs(m,root,0,0);
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(it->second.size()>1)
                sort(it->second.begin(),it->second.end());
        }
        map<int,vector<int>> n;
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(n.count(it->first.first)==0)
            {
                n[it->first.first]=it->second;
                continue;
            }
            vector<int> v=it->second;
            vector<int> u=n[it->first.first];
            u.insert(u.end(),v.begin(),v.end());
            n[it->first.first]=u;
        }
        for(auto it=n.begin();it!=n.end();it++)
        {
            sol.push_back(it->second);
        }
        return sol;
    }
};
