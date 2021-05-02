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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        ListNode* node=head;
        int count=0;
        while(node)
        {
            if(count++>n)
                temp=temp->next;
            node=node->next;
        }
        if(count<=n)
            return temp->next;
        temp->next=temp->next->next;
        return head;
    }
};
