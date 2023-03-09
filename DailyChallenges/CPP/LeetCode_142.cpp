class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head,*fast = head;
        while(slow && fast){
            slow=slow->next;
            fast=fast->next;
            if(fast) fast=fast->next;
            if(slow==fast) break;
        }
        if(!fast or !slow) return NULL;

        ListNode* res = head;
        while(res!=slow){
            res = res->next;
            slow = slow->next;
        }
        return res;
    }
};
