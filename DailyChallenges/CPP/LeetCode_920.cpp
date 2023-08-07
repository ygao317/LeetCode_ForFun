class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        int MOD = 1e9 + 7;
        vector<vector<long>> dp(goal + 1, vector<long>(n + 1, 0)); // i with j unique song
        dp[0][0] = 1;

        for (int i = 1; i <= goal; i++)
            for (int j = 1; j <= min(i, n); j++) { // add a song to the list
                dp[i][j] = dp[i - 1][j - 1] * (n - j + 1) % MOD; // The i-th song is a new song
                if (j > k) // The i-th song is a song we have played before
                    dp[i][j] = (dp[i][j] + dp[i - 1][j] * (j - k)) % MOD;
                
            }

        return dp[goal][n];
    }
};
