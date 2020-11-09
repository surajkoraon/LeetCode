class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int len1 = length(l1);
        int len2 = length(l2);
        
        int k=abs(len1 - len2);
        
        if(len2 > len1){
            ListNode* _temp = l1;
            l1 = l2;
            l2 = _temp;
        }
        
        ListNode* temp = l1;
        
        while(k--){
            temp = temp->next;
        }
            
        while(temp){
            temp->val += l2->val;
            l2 = l2->next;
            temp = temp->next;
        }
            
        l1 = handleCarry(l1, NULL);
        if(l1->val >= 10){
            ListNode* out = new ListNode(1);
            l1->val = l1->val%10;
            out->next = l1;
            return out;
        }
        return l1;
    }
    
    ListNode* handleCarry(ListNode* l1, ListNode* prev){
        if(l1->next == NULL) return l1;
        ListNode* node = handleCarry(l1->next, l1);
        if(l1->next->val >= 10){
            l1->next->val %=10;
            l1->val += 1;
        }
        return l1;
    }
    
    int length(ListNode* l){
        int len = 0;
        while(l){
            len++;
            l = l->next;
        }
        return len;
    }
    
};
