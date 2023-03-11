class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        function<TreeNode* (ListNode*, ListNode *)> build = [&](ListNode * st, ListNode * ed) -> TreeNode* {
            if (st == ed) return nullptr;
            ListNode * sl = st, * ft = st;
            while (ft != ed && ft->next != ed){
                sl = sl->next; ft = ft->next->next;
            }
            return new TreeNode(sl->val, build(st,sl), build(sl->next, ed));
        };

        return build(head, nullptr);
    }
};
