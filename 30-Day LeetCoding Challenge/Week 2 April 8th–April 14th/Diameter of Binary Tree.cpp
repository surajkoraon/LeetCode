    /**
     * Definition for a binary tree node.
     * struct TreeNode {
     *     int val;
     *     TreeNode *left;
     *     TreeNode *right;
     *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     * };
     */
    class Solution {
    public:
        int height(struct TreeNode* node) 
        { 
           if(node == NULL) 
               return 0;   
           return 1 + max(height(node->left), height(node->right)); 
        } 
        int diameterOfBinaryTree(TreeNode* tree) {
            if (tree == NULL) 
                 return 0; 
          int lheight = height(tree->left); 
          int rheight = height(tree->right);
          cout<<lheight<<" "<<rheight<<endl;   
          int ldiameter = diameterOfBinaryTree(tree->left); 
          int rdiameter = diameterOfBinaryTree(tree->right); 
          return max(lheight + rheight, max(ldiameter, rdiameter));
        }
    };