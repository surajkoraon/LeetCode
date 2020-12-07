/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void dfs(Node* root)
    {
        Node* tempChild = new Node(0);
        while (root) {
            Node* currentChild = tempChild;
            while (root) {
                if (root->left) 
                {
                    currentChild->next = root->left;
                    currentChild = currentChild->next;
                }
                if (root->right) 
                {
                    currentChild->next = root->right;
                    currentChild = currentChild->next;
                }
                root = root->next;
            }
            root = tempChild->next;
            tempChild->next = NULL;
        }
    }
    Node* connect(Node* root) {
        dfs(root);
        return root;
    }
};
