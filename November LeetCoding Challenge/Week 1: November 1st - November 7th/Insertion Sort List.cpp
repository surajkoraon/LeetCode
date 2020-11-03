/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head)
            return NULL;
        ListNode* root=head;
        ListNode* dummy=new ListNode;
        ListNode* temp=dummy;
        dummy->next=head;
        while(root)
        {
            if(root->next && root->val>root->next->val)
            {
                while(temp->next && temp->next->val<=root->next->val)
                {
                    temp=temp->next;
                }
                int x=root->next->val;
                int y=x;
                temp=temp->next;
                while(temp->val!=x)
                {
                    int z=temp->val;
                    temp->val=y;
                    y=z;
                    temp=temp->next;
                }
                temp->val=y;
            }
            root=root->next;
            temp=dummy;
        }
        return dummy->next;
    }
};
