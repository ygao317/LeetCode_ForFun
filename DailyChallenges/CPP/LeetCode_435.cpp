class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& x, const auto& y){
            return x[1] < y[1] || (x[1]==y[1] && x[0] < y [0]);
        });
        int n = intervals.size(), l = -1;
        vector<int> dp(n+1, 0); 
        for (int r=0; r<n; ++r){
            while (intervals[l+1][1] <= intervals[r][0]) ++l;
            dp[r+1] = max(dp[l+1]+1, dp[r]);
        }
        return n - dp[n];
    }
};
