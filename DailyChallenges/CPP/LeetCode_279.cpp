// 279. Perfect Squares @ 2022/11/22

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX); dp[0]=0;
        
        int sq = 1;
        for (int num = 1; (sq= num*num)<=n; ++num)
            for (int i = sq; i<=n; ++i)
                dp[i] = min(dp[i-sq]+1, dp[i]);
        
        return dp[n];
    }
};
