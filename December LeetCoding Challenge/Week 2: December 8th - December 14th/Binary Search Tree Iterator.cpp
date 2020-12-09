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
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        left_branch(root);
    }
    
    int next() {
        TreeNode* root=st.top();
        st.pop();
        if(root->right)
            left_branch(root->right);
        return root->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    void left_branch(TreeNode* root)
    {
        st.push(root);
        while(root->left)
        {
            st.push(root->left);
            root=root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
