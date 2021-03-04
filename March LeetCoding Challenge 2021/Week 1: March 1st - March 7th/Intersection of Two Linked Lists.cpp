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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a=headA;
        ListNode* b=headB;
        int counta=0,countb=0;
        while(a)
        {
            counta++;
            a=a->next;
        }
        while(b)
        {
            countb++;
            b=b->next;
        }
        if(counta<countb)
        {
            b=headB;
            int shift=countb-counta;
            while(shift--)
            {
                b=b->next;
            }
            a=headA;
        }
        else
        {
            a=headA;
            int shift=counta-countb;
            while(shift--)
            {
                a=a->next;
            }
            b=headB;
        }
        while(a)
        {
            if(a==b)
                return a;
            else
            {
                a=a->next;
                b=b->next;
            }
        }
        return NULL;
    }
};
