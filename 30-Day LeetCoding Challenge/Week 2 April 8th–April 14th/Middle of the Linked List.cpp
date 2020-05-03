/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* length=head;
        int c=0; 
        while(length)
        {
            c++;
            length=length->next;
        }
        ListNode* mid=head;
        ListNode* header=head;
        while(header->next&&header->next->next)
        {
            mid=mid->next;
            header=header->next->next;
        }
        if(c%2)
            return mid;
        return mid->next;
    }
};