class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        int mod = 1e9 + 7;
        for (auto& t : types)
            for (int i = target; i > 0; --i)
                for (int k = 1; k <= t[0] && i - t[1] * k >= 0; ++k)
                    dp[i] = (dp[i] + dp[i - t[1] * k]) % mod;
        return dp[target];
    }
};
