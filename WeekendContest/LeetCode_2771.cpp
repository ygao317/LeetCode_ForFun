class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), ans = 1, dp[2][n+1];
        dp[0][0] = dp[1][0] = 1;
        for (int i = 1; i < n; i++) {
            dp[0][i] = dp[1][i] = 1;
            if (nums2[i-1] <= nums1[i]) dp[0][i] = max(dp[1][i-1] + 1, dp[0][i]);
            if (nums1[i-1] <= nums1[i]) dp[0][i] = max(dp[0][i-1] + 1, dp[0][i]);
            if (nums2[i-1] <= nums2[i]) dp[1][i] = max(dp[1][i-1] + 1, dp[1][i]);
            if (nums1[i-1] <= nums2[i]) dp[1][i] = max(dp[0][i-1] + 1, dp[1][i]);
            ans = max({ans, dp[0][i], dp[1][i]});
        }
        return ans;
    }
};
