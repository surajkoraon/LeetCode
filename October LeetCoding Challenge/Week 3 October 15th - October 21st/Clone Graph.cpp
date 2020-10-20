/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int,Node*> dp;
    Node* recurse(Node* node)
    {
        if(dp.count(node->val)>0)
            return dp[node->val];
        Node* root = new Node(node->val);
        dp[node->val]=root;
        for(Node* neighbor:node->neighbors)
        {
            root->neighbors.push_back(recurse(neighbor));
        }
        return root;
    }
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        return recurse(node);
    }
};
