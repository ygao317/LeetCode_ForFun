class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = parent.size();
        long long res = 0;
        vector<int> dp(n);
        unordered_map<int, int> count;
        for (int i = 0; i < n; i++) {
            int mask = f(dp, parent, s, i);
            for (int j = 0; j < 26; j++)
                res += count.count(mask ^ (1 << j)) ? count[mask ^ (1 << j)] : 0;
            res += count[mask]++;
        }
        return res;
    }

    int f(vector<int>& dp, vector<int>& parent, string& s, int i) {
        if (i > 0 && dp[i] == 0)
            dp[i] = f(dp, parent, s, parent[i]) ^ (1 << (s[i] - 'a'));
        return dp[i];
    }
};
