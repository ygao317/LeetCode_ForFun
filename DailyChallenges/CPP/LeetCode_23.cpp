class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b)->bool { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (auto l: lists) { if (l) pq.push(l); }
        ListNode* ans = nullptr;
        while (!pq.empty()){
            auto l = pq.top(); pq.pop();
            if (l){
                if (l->next) pq.push(l->next);
                l->next = ans;
                ans = l;
            }
        }
        
        function<ListNode* (ListNode*, ListNode*)> rev = [&](ListNode* a, ListNode* b) {
            if (!a) return b; else{
                auto _a = a->next;
                a->next = b; 
                return rev(_a, a);
            }
        };
        
        return rev(ans, nullptr);
    }
};
