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
    map<int,vector<pair<int,int>>> m;
    void BFS(TreeNode* root)
    {
        if(!root)
            return;
        queue<pair<TreeNode*,int>> q;
        int size;
        q.push({root,0});
        int height=0;
        while(!q.empty())
        {
            size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* temp=q.front().first;
                int index=q.front().second;
                m[index].push_back({height,temp->val});
                q.pop();
                if(temp->left)
                {
                    q.push({temp->left,index-1});
                }
                if(temp->right)
                {
                    q.push({temp->right,index+1});
                }
            }
            height++;
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        BFS(root);
        vector<vector<pair<int,int>>> v;
        for(auto it=m.begin();it!=m.end();it++)
        {
            sort(it->second.begin(),it->second.end(),[&](pair<int,int> a,pair<int,int> b)
                 {
                     return a.first==b.first?a.second<b.second:a.first<b.first;
                 });
            v.push_back(it->second);
        }
        vector<vector<int>> sol;
        for(int i=0;i<v.size();i++)
        {
            vector<int> tmp;
            for(int j=0;j<v[i].size();j++)
            {
                tmp.push_back(v[i][j].second);
            }
            sol.push_back(tmp);
        }
        return sol;
    }
};