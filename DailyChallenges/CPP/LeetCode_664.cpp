class Solution {
public:
    int strangePrinter(string s) {
        s.erase(unique(s.begin(), s.end()), s.end());
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n+1, INT_MAX)); // [i, j)
        for (int i=0; i<n; ++i){ dp[i][i] = 0; dp[i][i+1] = 1; }

        for (int k=2; k <=n; ++k)
            for (int i = 0; i<= n-k; ++i)
                for (int j = i+1; j < i+k; ++j)
                    dp[i][i+k] = min(dp[i][i+k], dp[i][j] + ((s[j-1] == s[i+k-1])? dp[j][i+k-1] : dp[j][i+k]));

        return dp[0][n];
    }
};
