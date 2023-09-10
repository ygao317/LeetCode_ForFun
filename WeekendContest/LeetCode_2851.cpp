class Solution {
    const int M = 1000000007;

    int add(int x, int y) {
        if ((x += y) >= M) {
            x -= M;
        }
        return x;
    }

    int mul(long long x, long long y) {
        return x * y % M;
    }
    
public:
    int numberOfWays(string s, string t, int k) {
        const int n = s.length();
        vector<int> dp = {1, 0};
        for (; k; --k) {
            dp = {mul(dp[1], n - 1), add(dp[0], mul(n - 2, dp[1]))};
        }
        int r = 0;
        for (int i = 0; i < n; ++i) {
            bool ok = true;
            for (int j = 0; ok && j < n; ok = s[(i + j) % n] == t[j], ++j)
            ;
            if (ok) {
                r = add(r, dp[!!i]);
            }
        }
        return r;
    }
};
