class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        auto cmp = [](const vector<int>& x, const vector<int>& y){ 
            return x[1] < y[1] || (x[1] == y[1] && (x[0] < y[0] || (x[0]==y[0] && x[2] < y[2]))); };
        sort(events.begin(), events.end(), cmp);
        int n = events.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0)); // add i event, choose j events => max value
        for (int i = 1; i<= n; ++i){
            vector<int> st= {events[i-1][0]-1, events[i-1][0]-1, INT_MAX};
            int p = distance(events.begin(), lower_bound(events.begin(), events.begin() + i, st, cmp));
            for (int j = 1; j <= k; ++j){
                dp[i][j] = max(dp[i-1][j], dp[p][j-1] + events[i-1][2]);
            }
        }
        return dp[n][k];
    }
};
