class Solution {
public:
    int countSteppingNumbers(string low, string high) {
        int n = high.size(), kmod = int(1e9+7);
        vector<vector<int>> dp(12, vector<int>(n+1, 0)); // 0 and 11 is the boundary
        for (int i = 1; i<= 10; ++i) dp[i][0] = 1; // 
        for (int j = 1; j <= n; ++j)
            for (int i = 1; i <= 10; ++i)
                dp[i][j] = (dp[i-1][j-1] + dp[i+1][j-1]) % kmod;

        auto count = [&](const string & s){
            int n = s.size(), ret = 0;
            for (int j = 0; j < n-1; ++j) // 1 dig to n-1 dig
                for (int i = 2; i < 11; ++i) // 1 to 9
                    ret = (ret + dp[i][j]) % kmod;

            for (int i = 2; i <= s[0]-'0'; ++i)
                ret = (ret + dp[i][n-1]) % kmod;
            
            for (int k = 0; k <n-1; ++k){ // k form 0 to n+2
                if (s[k+1] > s[k] + 1) {
                    ret = (ret + dp[s[k]-'0'+1][n-k-1]) % kmod;
                    break;
                }
                if (s[k+1] == s[k]+1){
                    ret = (ret + dp[s[k]-'0'][n-k-2]) % kmod;
                    continue;
                }
                if (s[k+1] == s[k]){
                    ret = (ret + dp[s[k]-'0'][n-k-2]) % kmod;
                    break;
                }
                if (s[k+1] == s[k]-1) continue;
                break;
            }
            return ret;
        };

        function<int(const string&, int)> isStep = [&](const string&s, int k){
            int j = s.size() - k;
            if (j == 1) return 1;
            if (abs(s[k] - s[k+1]) == 1) return isStep(s, k+1);
            else return 0;
        };

        return (count(high) - count(low) + isStep(high, 0) + kmod) % kmod;
    }
};
