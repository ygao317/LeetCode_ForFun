class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if (n%2 == 0) return true;
        int dp[2][n+1]; // max points can get from i with step
        memset(dp, 0, sizeof dp);
        for (int k = 1; k<=n; ++k)
            for (int i=0; i+k<=n; ++i)
                dp[k%2][i] = max(nums[i] - dp[1-k%2][i+1], nums[i+k-1] - dp[1-k%2][i]);
        return dp[1][0] >= 0;
    }
};
