class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        auto left = head;
        int c = 0;
        while (left){
            if (++c == k) break;
            left = left->next;
        }

        auto right = head, node = left->next;
        while (node){
            node = node->next;
            right = right->next;
        }

        swap(left->val, right->val);
        return head;
    }
};
