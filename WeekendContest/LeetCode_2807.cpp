class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head->next) return head;
        auto m = new ListNode(gcd(head->val, head->next->val), insertGreatestCommonDivisors(head->next));
        head->next = m;
        return head;
    }
};
