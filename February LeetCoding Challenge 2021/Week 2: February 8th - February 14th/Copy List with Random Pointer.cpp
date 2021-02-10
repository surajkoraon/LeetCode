/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        Node* node=head;
        while(node)
        {
            Node* next=node->next;
            Node* random=node->random;
            node->next=new Node(node->val);
            node=node->next;
            node->next=next;
            node->random=random;
            node=node->next;
        }
        node=head;
        while(node)
        {
            node=node->next;
            if(node->random)
                node->random=node->random->next;
            node=node->next;
        }
        node=head;
        Node* root=head->next;
        Node* copy=root;
        while(root)
        {
            node->next=root->next;
            if(root->next)
                root->next=root->next->next;
            node=node->next;
            root=root->next;
        }
        return copy;
    }
};