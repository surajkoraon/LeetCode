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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        return mergeKLists(lists,0,lists.size()-1);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists,int start,int end)
    {
        if(start==end)
            return lists[start];
        int mid=start+(end-start)/2;
        ListNode* left=mergeKLists(lists,start,mid);
        ListNode* right=mergeKLists(lists,mid+1,end);
        return mergeLists(left,right);
    }
    ListNode* mergeLists(ListNode* a,ListNode* b)
    {
        ListNode* l=new ListNode();
        ListNode* dummy=l;
        while(a && b)
        {
            if(a->val<b->val)
            {
                l->next=a;
                l=l->next;
                a=a->next;
            }
            else
            {
                l->next=b;
                l=l->next;
                b=b->next;
            }
        }
        if(a)
            l->next=a;
        if(b)
            l->next=b;
        return dummy->next;
    }
};
