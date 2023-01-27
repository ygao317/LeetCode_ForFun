class Solution {
public:
    int minCost(vector<int>& nums, int k){
        int n = nums.size();
        vector<int> dp(n+1, INT_MAX); dp[0] = 0;
        for (int i = 1; i <= n; ++i){
            vector<int> cnt(1001);
            //unordered_map<int, int> cnt;
            int cost = k;
            for (int j=i-1; j>=0; --j){
                ++cnt[nums[j]];
                if (cnt[nums[j]] == 2) cost += 2;
                if (cnt[nums[j]] > 2) cost += 1;
                dp[i] = min(dp[i], dp[j] + cost);
            }
        }
        return dp[n];
    }
};
