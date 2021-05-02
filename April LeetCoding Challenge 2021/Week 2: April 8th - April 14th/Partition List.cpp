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
    ListNode* partition(ListNode* head, int x) {
        ListNode* large;
        ListNode* largePrev;
        ListNode* prev=NULL;
        ListNode* node=head;
        bool flag=true;
        while(node)
        {
            if(node->val>=x && flag)
            {
                large=node;
                flag=false;
                largePrev=prev;
            }
            else if(node->val<x && !flag)
            {
                prev->next=node->next;
                node->next=large;
                if(largePrev)
                {
                    largePrev->next=node;
                }
                else
                {
                    head=node;
                }
                largePrev=node;
                node=prev;
            }
            prev=node;
            node=node->next;
            // cout<<prev->val<<" ";
            // if(node)
            //     cout<<node->val<<endl;
        }
        return head;
    }
};
