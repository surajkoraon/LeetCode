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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return NULL;
        if(head->next && head->val==head->next->val)
        {
            while(head)
            {
                if(head->next && head->val==head->next->val)
                    head=head->next;
                else
                    return deleteDuplicates(head->next);
            }
        }
        ListNode* a=head;
        ListNode* b=head->next;
        while(b)
        {
            if(b->next && b->val==b->next->val)
            {
                a->next=deleteDuplicates(b);
            }
            a=a->next;
            if(a)
                b=a->next;
            else
                b=NULL;
        }
        return head;
    }
};
