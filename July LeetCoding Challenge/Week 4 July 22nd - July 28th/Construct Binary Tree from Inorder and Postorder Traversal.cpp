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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        return recurse(inorder,0,inorder.size(),postorder,0,postorder.size());
    }
private:
    TreeNode* recurse(vector<int>& inorder,int i,int j,vector<int>& postorder,int x,int y)
    {
        if(i>=j || x>=y)
            return NULL;
        
        int mid=postorder[y-1];
        
        auto f = find(inorder.begin()+i,inorder.begin()+j,mid);
        
        int dis=f-inorder.begin()-i;
        
        TreeNode* root = new TreeNode(mid);
        root->left=recurse(inorder,i,i+dis,postorder,x,x+dis);
        root->right=recurse(inorder,i+dis+1,j,postorder,x+dis,y-1);
        
        return root;
        
    }
};
