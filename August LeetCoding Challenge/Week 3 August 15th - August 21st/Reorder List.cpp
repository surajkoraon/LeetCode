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
    ListNode* reverse(ListNode* head)
    {
        ListNode* temp;
        ListNode* prev=NULL;
        while(head)
        {
            temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head && head->next && head->next->next)
        {
                ListNode* root=head;
            ListNode* temp=head->next->next;
            while(temp)
            {
                head=head->next;
                if(temp->next)
                    temp=temp->next->next;
                else
                    break;
            }
            ListNode* d=head->next;
            head->next=NULL;
            ListNode* rev=reverse(d);
            ListNode* fh=root;
            ListNode* a=new ListNode;
            ListNode* b=new ListNode;
            ListNode* c=new ListNode;
            while(1)
            {
                cout<<fh->val<<endl;
                //cout<<1<<endl;
                c=fh;
                a=fh->next;
                b=rev->next;
                fh->next=rev;
                rev->next=a;
                fh=a;
                rev=b;
                if(!fh || !rev)
                    break;
            }
            if(rev)
                c->next=rev;
            head=root;
        }
        
    }
};
