class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(4); // backwards only 3
        int n = stoneValue.size();
        for (int i = n-1; i >= 0; --i){ // O(n) from back to front
            dp[i%4] = INT_MIN;
            for (int j = 0, taken = 0; j<3 && i+j<n; ++j) // O(3)
                dp[i%4] = max(dp[i%4], (taken += stoneValue[i+j]) - dp[(i+j+1)%4]); 
        }
        return dp[0] == 0 ? "Tie" : (dp[0] > 0 ? "Alice" : "Bob");
    }
};
