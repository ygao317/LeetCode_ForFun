class Solution {
public:
    int maximizeWin(vector<int>& A, int k) {
        int res = 0, n = A.size(), j = 0; // left point
        vector<int> dp(n + 1, 0); // max number for one segment in first index elements.
        for (int i = 0; i < n; ++i) { // right point
            while (A[j] < A[i] - k)
                ++j;
            dp[i + 1] = max(dp[i], i - j + 1); // update first
            res = max(res, i - j + 1 + dp[j]); // two segments
        }
        return res;
    }
};
