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
    ListNode* swapNodes(ListNode* head, int k) {
        int size=0;
        ListNode* node=head;
        ListNode* b=NULL;
        ListNode* a=NULL;
        int count=0;
        while(node)
        {
            count++;
            if(count==k)
            {
                a=node;
                b=head;
            }
            node=node->next;
            if(b && node)
            {
                b=b->next;
            }
        }
        int temp=a->val;
        a->val=b->val;
        b->val=temp;
        return head;
    }
};
