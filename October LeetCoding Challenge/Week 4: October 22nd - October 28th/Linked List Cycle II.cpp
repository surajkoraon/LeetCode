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
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return NULL;
        ListNode* slow=head;
        ListNode* fast=head->next;
        bool flag=false;
        int count=0;
        while(fast && fast->next)
        {
            count++;
            if(slow==fast)
            {
                flag=true;
                break;
            }
            slow=slow->next;
            fast=fast->next->next;
        }
        if(!flag)
            return NULL;
        ListNode* root=head;
        while(root)
        {
            ListNode* temp=root->next;
            int i=0;
            while(i++<=count)
            {
                if(temp==root)
                    return root;
                temp=temp->next;
            }
            root=root->next;
        }
        return NULL;
    }
};
