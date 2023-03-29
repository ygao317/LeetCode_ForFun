class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<int> dp(n+1, INT_MIN); dp[0] = 0;
        for (int i=1; i<=n; ++i){
            for (int j=i; j>0; --j)
                dp[j] = max(dp[j], dp[j-1] + j * satisfaction[i-1]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};
