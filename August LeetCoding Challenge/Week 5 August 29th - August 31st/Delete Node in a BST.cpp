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
    TreeNode* sol=NULL;
    int flag=0;
    vector<TreeNode*> replace(TreeNode* node,TreeNode *head)
    {
        TreeNode* parent=head;
        TreeNode* succ=node;
        while(node->left!=NULL)
        {
            parent=node;
            succ=node->left;
            node=node->left;
        }
        return {parent,succ};
    }
    void deletekey(TreeNode* root, int key,TreeNode* parent,int child,TreeNode *head)
    {
        vector<TreeNode*> v;
        if(root->right && root->left)
        {
            v=replace(root->right,head);
            if(v[0]==head)
            {
                root->val=v[1]->val;
                root->right=v[1]->right;
            }
            else
            {
                root->val=v[1]->val;
                v[0]->left=v[1]->right;
            }
        }
        else if(root->right)
        {
            if(parent)
            {
                if(child==1)
                {
                    parent->right=root->right;
                }
                else
                {
                    parent->left=root->right;
                }
            }
            else
            {
                head=root->right;
            }
        }
        else if(root->left)
        {
            if(parent)
            {
                if(child==1)
                {
                    parent->right=root->left;
                }
                else
                {
                    parent->left=root->left;
                } 
            }
            else
            {
                head=root->left;
            }
        }
        else
        {
            cout<<root->val;
            if(parent)
            {
                if(child==0)
                    parent->left=NULL;
                if(child==1)
                    parent->right=NULL;
            }
            else
            {
                head=NULL;
            }
        }
        sol=head;
    }
    void dfs(TreeNode* root, int key,TreeNode* parent,int child,TreeNode *head)
    {
        if(!root)
            return;
        if(root->val==key)
        {
            flag=1;
            deletekey(root,key,parent,child,head);
            return;
        }
        parent=root;
        if(root->val<key)
            dfs(root->right,key,parent,1,head);
        else
            dfs(root->left,key,parent,0,head);
        
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        if(root->left==NULL && root->right==NULL && root->val==key)
        {
            return NULL;
        }
        TreeNode *head=root;
        TreeNode * parent=NULL;
        dfs(root,key,parent,-1,head);
        if(flag==0)
            return head;
        return sol;
    }
};
