class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<ListNode*> v1, v2;
        while (l1) v1.push_back(l1), l1 = l1->next;
        while (l2) v2.push_back(l2), l2 = l2->next;
        int n1 = v1.size(), n2 = v2.size(), c = 0;
        if (n1 < n2) swap(v1, v2), swap(n1, n2);
        for (int i = 1; i<=n1; ++i){
            int a = v1[n1-i]->val + (n2-i>=0 ? v2[n2-i]->val : 0) + c;
            v1[n1-i]->val =  a % 10;
            c = a / 10;
        }
        return (c==1) ? new ListNode(c, v1[0]) : v1[0];
    }
};
