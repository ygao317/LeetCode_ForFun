class Solution {
public:
    int numberOfWays(int n, int x) {
        int dp[301] = {1}, mod = 1e9 + 7, v;
        for (int a = 1; (v = pow(a, x)) <= n; ++a) // each round, add one power(a, x)
            for (int i = n; i >= v; i--) // update the impact from end to front.
                dp[i] = (dp[i] + dp[i - v]) % mod;
        return dp[n];
    }
};
