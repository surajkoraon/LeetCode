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
    int sum=0;
    vector<string> v;
    void summation()
    {
        int total;
        for(string str:v)
        {
            total=0;
            cout<<str<<" ";
            for(int i=str.size()-1;i>=0;i--)
            {
                if(str[i]=='1')
                    total+=1<<(str.size()-1-i);
            }
            sum+=total;
        }
    }
    void dfs(TreeNode* root,string s)
    {
        if(!root)
            return;
        s+=to_string(root->val);
        if(!root->left && !root->right)
        {
            v.push_back(s);
            return;
        }
        dfs(root->left,s);
        dfs(root->right,s);
    }
    int sumRootToLeaf(TreeNode* root) {
        dfs(root,"");
        summation();
        return sum;
    }
};