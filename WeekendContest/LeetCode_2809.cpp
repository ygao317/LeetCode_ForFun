class Solution {
public:
    int minimumTime(vector<int>& A, vector<int>& B, int x) {
        int n = A.size(), sa = accumulate(A.begin(), A.end(), 0), sb = accumulate(B.begin(), B.end(), 0);
        
        vector<vector<int>> BA;
        for (int i = 0; i < n; i++) BA.push_back({B[i], A[i]});
        sort(BA.begin(), BA.end());

        vector<int> dp(n + 1); // max value can remove after n second
        for (int j = 0; j < n; ++j) // at most, do n second
            for (int i = j + 1; i > 0; --i)
                dp[i] = max(dp[i], dp[i - 1] + i * BA[j][0] + BA[j][1]); // from the smallest step to remove

        for (int i = 0; i <= n; ++i)
            if (sb * i + sa - dp[i] <= x)
                return i;
        
        return -1;
    }
};
