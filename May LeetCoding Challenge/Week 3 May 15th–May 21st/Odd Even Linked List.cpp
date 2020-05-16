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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)
            return head;
        if(head->next==NULL)
            return head;
        if(head->next->next==NULL)
            return head;
        ListNode *odd=head,*even=head->next,*merge=even;
        while(odd->next && odd->next->next)
        {
            odd->next=odd->next->next;
            if(even->next)
                even->next=even->next->next; 
            even=even->next;
            odd=odd->next;
        }
        odd->next=merge;
        return head;
    }
};
