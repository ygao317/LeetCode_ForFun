class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        for (int i = n; i > 2; i-=2){
            ans += abs(cost[i-1] - cost[i-2]);
            cost[i/2-1] += max(cost[i-1],cost[i-2]);
        }
        return ans;
    }
};
