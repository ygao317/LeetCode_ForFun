// 2462. Total Cost to Hire K Workers

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long ans = 0;
        if (k == n){ // no need sort or prioritize, just add.
            for (int i=0; i<k; ++i)
                ans += costs[i];
        } else if (2 * candidates >= n){ // no need two pq, just sort
            sort(begin(costs), end(costs));
            for (int i=0; i<k; ++i)
                ans += costs[i];
        }else { // two priority queue to take
            int l = candidates, r = n-candidates-1;
            priority_queue<int, vector<int>, greater<int>> lpq, rpq;
            for (int i = 0; i<l; ++i) lpq.push(costs[i]);
            for (int i= n-1; i>r; --i) rpq.push(costs[i]);
            
            for (int i =0; i<k; ++i){
                if (!lpq.empty() && (rpq.empty() || lpq.top() <= rpq.top())){
                    ans += lpq.top(); lpq.pop();
                    if (l<=r) lpq.push(costs[l++]);
                } else {
                    ans += rpq.top(); rpq.pop();
                    if (l<=r) rpq.push(costs[r--]);
                }
            }
        }
        
        return ans;
    }
};
