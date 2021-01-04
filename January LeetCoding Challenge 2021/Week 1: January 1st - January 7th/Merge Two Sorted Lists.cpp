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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode* l=NULL;
        if(l1->val<l2->val)
        {
            l=l1;
            l1=l1->next;
        }
        else
        {
            l=l2;
            l2=l2->next;
        }
        ListNode* sol=l;
        while(l1 && l2)
        {
            ListNode* temp=NULL;
            if(l1->val<l2->val)
            {
                temp=l1->next;
                l->next=l1;
                l=l->next;
                l1=temp;
            }
            else
            {
                temp=l2->next;
                l->next=l2;
                l=l->next;
                l2=temp;
            }
        }
        if(l1)
            l->next=l1;
        if(l2)
            l->next=l2;
        return sol;
    }
};
