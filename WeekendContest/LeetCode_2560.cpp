class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        vector<vector<int>> dp(2, vector<int>(k+1,-1)); // init as -1
        dp[0][0] = 0;
        
        for (int i = 0; i < nums.size(); ++i){
            int num = nums[i];
            // if take it
            for (int j=min(k-1, i/2); j>=0; --j){
                dp[0][j+1] = max(dp[0][j], num);
            }
            swap(dp[0], dp[1]);
        }
        
        return min(dp[0][k], dp[1][k]);
    }
};
