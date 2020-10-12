/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        serialiseDFS(root,s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos=0;
        TreeNode* root;
        return deserializeDFS(data,pos,INT_MIN,INT_MAX);
    }
    void serialiseDFS(TreeNode* root, string& s)
    {
        if(!root)
            return;
        s+=to_string(root->val)+",";
        serialiseDFS(root->left,s);
        serialiseDFS(root->right,s);   
    }
    TreeNode* deserializeDFS(string data,int& pos,int lower,int upper)
    {
        if(pos>=data.length())
            return NULL;
        int index=pos;
        while(data[index]!=',')
        {
            index++;
        }
        int val=stoi(data.substr(pos,index-pos));
        if(val>upper || val<lower)
            return NULL;
        pos=index+1;
        TreeNode* node = new TreeNode(val);
        node->left=deserializeDFS(data,pos,lower,val);
        node->right=deserializeDFS(data,pos,val,upper);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
