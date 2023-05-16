class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        auto f = head;
        while (f && f->next){
            swap(f->val, f->next->val);
            f = f->next->next;
        }
        return head;
    }
};
