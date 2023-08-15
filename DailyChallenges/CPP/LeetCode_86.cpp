class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;
        ListNode* lh(nullptr), *rh(nullptr), *lt(nullptr), *rt(nullptr);
        while (head){
            if (head->val < x){
                if (!lt) {lh = lt= head; } else{ lt->next = head; lt = lt->next; }
            } else {
                if (!rt) {rh = rt= head; } else { rt->next = head; rt = rt->next; }
            }
            head = head->next;
        }
        if (lh) lt->next = rh; else lh = rh;
        if (rt) rt->next = nullptr; else lt->next = nullptr;
        return lh;
    }
};
