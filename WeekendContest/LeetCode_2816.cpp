class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        function<int(ListNode*)> d = [&](ListNode* node){
            if (!node) return 0;
            int x = node->val * 2 + d(node->next);
            node->val = x % 10;
            return x>9?1:0;
        };
        return d(head) == 1 ? new ListNode(1, head) : head;
    }
};
