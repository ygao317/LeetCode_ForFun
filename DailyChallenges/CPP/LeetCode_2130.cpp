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
    int pairSum(ListNode* head) {
        auto slow = head, fast = head->next;
        vector<int> v; v.push_back(head->val);
        while(fast->next){
            slow = slow->next;
            v.push_back(slow->val);
            fast = fast->next->next;
        }
        int ans = 0;
        for (int i = v.size()-1; i>=0; --i){
            slow = slow->next;
            ans = max(ans, v[i] + slow->val);
        }
        return ans;
    }
};
