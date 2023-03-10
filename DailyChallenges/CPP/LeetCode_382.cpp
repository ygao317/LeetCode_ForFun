class Solution {
public:
    vector<ListNode*> v;
    Solution(ListNode* head) {
        while (head){
            v.push_back(head);
            head = head->next;
        }
    }
    
    int getRandom() {
        return v[rand()%v.size()]->val;
    }
};
