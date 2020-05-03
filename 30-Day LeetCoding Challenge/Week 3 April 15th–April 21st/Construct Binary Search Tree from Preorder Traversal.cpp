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
    /*TreeNode* createBST(int &curr,int min_val, 
                        int max_val, vector<int>& preorder) {
        if(curr >= preorder.size() || preorder[curr] < min_val ||
            preorder[curr] > max_val)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[curr++]);
        root->left = createBST(curr, min_val, root->val, preorder);
        root->right = createBST(curr, root->val, max_val, preorder);
        return root;
    }*/
    
    TreeNode* solve(vector<int> &preorder, int &currentIndex, int changeCriteria){
        if(currentIndex == preorder.size() || preorder[currentIndex] > changeCriteria){
            return NULL;
        }
        // cout<<currentIndex<<" "<<changeCriteria<<endl;
        TreeNode *root = new TreeNode(preorder[currentIndex]);
        currentIndex++;
        root->left = solve(preorder, currentIndex , root->val);
        root->right = solve(preorder, currentIndex, changeCriteria);
        
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        /*if(preorder.empty())
            return nullptr;
        int curr = 0;
        return createBST(curr, INT_MIN, INT_MAX, preorder);
        */
        
        if(preorder.size() == 0) return NULL;
        int currentIndex  = 0;
        return solve(preorder, currentIndex, INT_MAX);
    }
};