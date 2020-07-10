/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)
            return head;
        Node* root=head;
        Node* a;
        stack<Node*> st;
        while(root)
        {
            if(root->child)
            {
                if(root->next)
                    st.push(root->next);
                root->next=root->child;
                root->child=NULL;
                root->next->prev=root;
            }
            if(!root->next)
                a=root;
            root=root->next;
        }
        while(!st.empty())
        {
            Node* temp=st.top();
            st.pop();
            a->next=temp;
            temp->prev=a;
            while(a->next)
            {
                a=a->next;
            }
        }
        return head;
    }
};
