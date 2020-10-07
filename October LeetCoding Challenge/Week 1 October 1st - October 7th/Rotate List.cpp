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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        int size=1;
        ListNode* temp=head;
        while(temp->next)
        {
            size++;
            temp=temp->next;
        }
        temp->next=head;
        k=k%size;
        int x=size-k-1;
        while(x--)
        {
            head=head->next;
        }
        ListNode* root=head->next;
        head->next=NULL;
        return root;
    }
};
